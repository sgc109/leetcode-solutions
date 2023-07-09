class Solution {
    int ROOT = 0;
    
    int N;
    vector<int> sizes;
    vector<int> sumUsed;
    vector<vector<int>> G;
    vector<int> ans;
    
    void dfs(int cur, int par) {
        sizes[cur] = 1;
        for(int child : G[cur]) {
            if(child == par) {
                continue;
            }
            dfs(child, cur);
            sizes[cur] += sizes[child];
            sumUsed[cur] += sizes[child] + sumUsed[child];
        }
    }
    
    void go(int cur, int par) {
        if(cur != ROOT) {
            ans[cur] = ans[par] - sizes[cur] + N - sizes[cur];
        }
        
        for(int child : G[cur]) {
            if(child == par) {
                continue;
            }
            go(child, cur);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        sizes = vector<int>(N, 0);
        sumUsed = vector<int>(N, 0);
        G = vector<vector<int>>(N, vector<int>());
        for(auto e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        ans = vector<int>(N, 0);
        ans[0] = sumUsed[0];
        
        go(0, -1);
        return ans;
    }
};