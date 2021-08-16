/*
dp[i][j]: whether i'th stone is reachable when the previous stone was j.

dp[1][0] = true
dp[i][j] = or(dp[j][k](0<=k<j 중에 k=in(2*j-i-1..2*j-i+1)))

ans: or(dp[N - 1][k])(0<=k<N-1)
*/

class Solution {
    bool dp[2001][2001];
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        int N = stones.size();
        unordered_map<int,int> index;
        for(int i = 0; i < N; i++) {
            index[stones[i]] = i;
        }
        dp[1][0] = true;
        for(int i = 2; i < N; i++) {
            for(int j = 0; j < i; j++) {
                for(int k = -1; k <= 1; k++) {
                    int prvPos = 2 * stones[j] - stones[i] + k;
                    if(index.count(prvPos) > 0) {
                        int prvIdx = index[prvPos];
                        dp[i][j] = dp[i][j] || dp[j][prvIdx];
                    }
                }
            }
        }
        
        for(int i = 0; i < N - 1; i++) {
            if(dp[N - 1][i]) return true;
        }
        return false;
    }
};