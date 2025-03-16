/*
Example 1
1 0
0 1

Example 2
1 1
1 0

Example 3
1 1
1 1
*/
class Solution {
    int N;
    vector<int> parents;
    vector<int> sizes;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    bool inRange(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }
    int find(int u) {
        if(parents[u] == u) {
            return u;
        }
        return parents[u] = find(parents[u]);
    }
    int merge(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) {
            return sizes[u];
        }
        if(sizes[u] > sizes[v]) {
            swap(u, v);
        }
        sizes[v] += sizes[u];
        parents[u] = v;
        return sizes[v];
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size();
        sizes = vector<int>(N * N, 1); 
        parents = vector<int>(N * N);
        for(int i = 0; i < N * N; ++i) {
            parents[i] = i; 
        }
        int ans = 1; // 4
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < N; ++c) {
                if(grid[r][c]) {
                    for(int k = 0; k < 4; ++k) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if(inRange(nr, nc) && grid[nr][nc]) {
                            int mergedSize = merge(r * N + c, nr * N + nc);
                            ans = max(ans, mergedSize);
                        }
                    }
                }
            }
        }
/*
1 1
1 1
sizes = [1, 4, 1, 1]
parents = [1, 1, 1, 1]
*/
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < N; ++c) {
                if(!grid[r][c]) {
                    set<int> setIds;
                    for(int k = 0; k < 4; ++k) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if(inRange(nr, nc) && grid[nr][nc]) {
                            setIds.insert(find(nr * N + nc));
                        }
                    }
                    int sumSize = 1; // 4
                    for(int setId : setIds) {
                        sumSize += sizes[setId];
                    }
                    ans = max(ans, sumSize);
                }
            }
        }
        return ans;
    }
};