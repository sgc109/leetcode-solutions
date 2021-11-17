
class Solution {
public:
    vector<int> vis;
    int N;
    void dfs(int cur, vector<vector<int>>& G){
        vis[cur] = 1;
        for(int i = 0; i < N; i++){
            if(vis[i] || !G[cur][i]) continue;
            dfs(i, G);
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        N = M.size();
        vis = vector<int>(N, 0);
        int ans = 0;
        for(int i = 0; i < N; i++){
            if(vis[i]) continue;
            dfs(i, M);
            ans++;
        }
        return ans;
    }
};