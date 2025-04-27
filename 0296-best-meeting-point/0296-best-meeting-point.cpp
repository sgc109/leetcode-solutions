class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<pair<int,int>> homes;
        vector<int> countR(R, 0);
        vector<int> countC(C, 0);
        int sumDistR = 0;
        int sumDistC = 0;
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                if(grid[i][j]) {
                    homes.emplace_back(i, j);
                    countR[i]++;
                    countC[j]++;
                    sumDistR += i;
                    sumDistC += j;
                }
            }
        }
        int N = homes.size();
        int cntR = countR[0];
        int minDR = sumDistR;
        int ansR = 0;
        for(int i = 1; i < R; ++i) {
            sumDistR -= N - cntR;
            sumDistR += cntR;
            if(minDR > sumDistR) {
                minDR = sumDistR;
                ansR = i;
            }
            cntR += countR[i];
        }
        int cntC = countC[0];
        int minDC = sumDistC;
        int ansC = 0;
        for(int i = 1; i < C; ++i) {
            sumDistC -= N - cntC;
            sumDistC += cntC;
            if(minDC > sumDistC) {
                minDC = sumDistC;
                ansC = i;
            }
            cntC += countC[i];
        }
        int ans = 0;
        for(auto& p : homes) {
            ans += abs(p.first - ansR) + abs(p.second - ansC);
        }
        return ans;
    }
};