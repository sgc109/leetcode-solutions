class Solution {
    int R, C;
    int dp[2][73][73];

    bool inRange(int x1, int x2) {
        return 0 <= x1 && x1 < C && 0 <= x2 && x2 < C;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();

        memset(dp, 0xcf, sizeof(dp));

        dp[0][0][C - 1] = grid[0][0] + grid[0][C - 1];

        for(int y = 1; y < R; ++y) {
            for(int x1 = 0; x1 < C; ++x1) {
                for(int x2 = x1; x2 < C; ++x2) {
                    for(int k = 0; k < 9; ++k) {
                        int px1 = x1 + "012012012"[k] - '1';
                        int px2 = x2 + "000111222"[k] - '1';
                        if(!inRange(px1, px2)) {
                            continue;
                        }
                        dp[y & 1][x1][x2] = max(
                            dp[y & 1][x1][x2], 
                            dp[(y + 1) & 1][px1][px2] + grid[y][x1] + (x1 != x2 ? grid[y][x2] : 0)
                        );
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < C; ++i) {
            for(int j = i; j < C; ++j) {
                ans = max(ans, dp[(R + 1) & 1][i][j]);
            }
        }
        return ans;
    }
};