class Solution {
    vector<int> par;
    vector<int> size;
    int N;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    bool inRange(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }
    int find(int u) {
        if(par[u] == u) {
            return u;
        }
        return par[u] = find(par[u]);
    }
    int merge(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) {
            return size[u];
        }
        if(size[u] > size[v]) {
            swap(u, v);
        }
        par[u] = v;
        size[v] += size[u];
        return size[v];
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        this->N = grid.size();
        par = vector<int>(N * N); //     [1, 1, 1, 3]
        size = vector<int>(N * N, 1); // [1, 3, 1, 1]
        for(int i = 0; i < N * N; ++i) {
            par[i] = i;
        }
        
        int ans = 1; // 3
        for(int r = 0; r < N; ++r) { // 0
            for(int c = 0; c < N; ++c) { // 0
                if(!grid[r][c]) {
                    continue;
                }
                for(int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(!inRange(nr, nc) || !grid[nr][nc]) {
                        continue;
                    }
                    int mergedSize = merge(r * N + c, nr * N + nc);
                    ans = max(ans, mergedSize);
                }
            }
        }

/*
1 1
1 0
*/
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < N; ++c) {
                if(grid[r][c]) {
                    continue;
                }
                set<int> uniqueGroupIds;
                for(int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(!inRange(nr, nc) || !grid[nr][nc]) {
                        continue;
                    }
                    uniqueGroupIds.insert(find(nr * N + nc));
                }
                int sumSize = 1;
                for(int groupId : uniqueGroupIds) {
                    sumSize += size[groupId];
                }
                ans = max(ans, sumSize);
            }
        }
        return ans;
    }
};