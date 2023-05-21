typedef long long ll;

class Solution {
    int N, M;
    bool inRange(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < M;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->N = obstacleGrid.size();
        this->M = obstacleGrid[0].size();
        if(obstacleGrid[N - 1][M - 1] == 1) {
            return 0;
        }
        vector<vector<ll>> dp = vector<vector<ll>>(N, vector<ll>(M, 0));
        dp[N - 1][M - 1] = 1;
        for(int i = N - 1; i >= 0; --i) {
            for(int j = M - 1; j >= 0; --j) {
                if(i == N - 1 && j == M - 1) {
                    continue;
                }
                if(obstacleGrid[i][j] == 1) {
                    continue;
                }
                ll tmp = 0;
                if(i + 1 < N) {
                    tmp += dp[i + 1][j];
                }
                if(j + 1 < M) {
                    tmp += dp[i][j + 1];
                }
                dp[i][j] = tmp;
            }
        }
        return dp[0][0];
    }
};