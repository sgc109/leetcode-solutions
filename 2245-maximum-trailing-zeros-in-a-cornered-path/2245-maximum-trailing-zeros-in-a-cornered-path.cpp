class Solution {
    int R, C;
    vector<int> calcCntOf2And5(int num) {
        int cnt2 = 0;
        int cnt5 = 0;
        while(num % 2 == 0 || num % 5 == 0) {
            if(num % 2 == 0) {
                cnt2++;
                num /= 2;
            }
            if(num % 5 == 0) {
                cnt5++;
                num /= 5;
            }
        }
        return vector<int>({cnt2, cnt5});
    }
    void init(int R, int C) {
        cntToLeft = vector<vector<vector<int>>>(R, vector<vector<int>>(C, vector<int>(2, 0)));
        cntToRight = vector<vector<vector<int>>>(R, vector<vector<int>>(C, vector<int>(2, 0)));
        cntToTop = vector<vector<vector<int>>>(R, vector<vector<int>>(C, vector<int>(2, 0)));
        cntToBottom = vector<vector<vector<int>>>(R, vector<vector<int>>(C, vector<int>(2, 0)));
    }

    vector<vector<vector<int>>> cntToLeft, cntToRight;
    vector<vector<vector<int>>> cntToTop, cntToBottom;

    void preprocess(vector<vector<int>>& grid) {
        for(int i = 0; i < R; ++i) {
            // For to left
            cntToLeft[i][0] = calcCntOf2And5(grid[i][0]);
            for(int j = 1; j < C; ++j) {
                auto cnt2And5 = calcCntOf2And5(grid[i][j]);
                cntToLeft[i][j][0] = cntToLeft[i][j - 1][0] + cnt2And5[0]; // for 2
                cntToLeft[i][j][1] = cntToLeft[i][j - 1][1] + cnt2And5[1]; // for 5
            }

            // For to right
            cntToRight[i][C - 1] = calcCntOf2And5(grid[i][C - 1]);
            for(int j = C - 2; j >= 0; --j) {
                auto cnt2And5 = calcCntOf2And5(grid[i][j]);
                cntToRight[i][j][0] = cntToRight[i][j + 1][0] + cnt2And5[0];
                cntToRight[i][j][1] = cntToRight[i][j + 1][1] + cnt2And5[1];
            }
        }

        for(int j = 0; j < C; ++j) {
            // For to top
            cntToTop[0][j] = calcCntOf2And5(grid[0][j]);
            for(int i = 1; i < R; ++i) {
                auto cnt2And5 = calcCntOf2And5(grid[i][j]);
                cntToTop[i][j][0] = cntToTop[i - 1][j][0] + cnt2And5[0];
                cntToTop[i][j][1] = cntToTop[i - 1][j][1] + cnt2And5[1];
            }

            // For to bottom
            cntToBottom[R - 1][j] = calcCntOf2And5(grid[R - 1][j]);
            for(int i = R - 2; i >= 0; --i) {
                auto cnt2And5 = calcCntOf2And5(grid[i][j]);
                cntToBottom[i][j][0] = cntToBottom[i + 1][j][0] + cnt2And5[0];
                cntToBottom[i][j][1] = cntToBottom[i + 1][j][1] + cnt2And5[1];
            }
        }
    }

    int calcCntTrailingZeros(vector<int>& cntHori, vector<int>& cntVert) {
        return min(cntHori[0] + cntVert[0], cntHori[1] + cntVert[1]);
    }
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();

        init(R, C);
        preprocess(grid);

        int ans = 0;
        auto emptyCnt = vector<int>({0, 0});
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                // to top
                // fix left
                ans = max(ans, calcCntTrailingZeros(cntToLeft[i][j], i > 0 ? cntToTop[i - 1][j] : emptyCnt));

                // fix right
                ans = max(ans, calcCntTrailingZeros(cntToRight[i][j], i > 0 ? cntToTop[i - 1][j] : emptyCnt));

                // to bottom
                // fix left
                ans = max(ans, calcCntTrailingZeros(cntToLeft[i][j], i < R - 1 ? cntToBottom[i + 1][j] : emptyCnt));

                // fix right
                ans = max(ans, calcCntTrailingZeros(cntToRight[i][j], i < R - 1 ? cntToBottom[i + 1][j] : emptyCnt));
            }
        }

        return ans;
    }
};