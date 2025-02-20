/*
0 1
1 0

*/

class Solution {
    int R, C;
    vector<int> parent;
    vector<int> sizes;

    int dr[4] = {0, -1, 1, 0};
    int dc[4] = {-1, 0, 0, 1};

    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }

    int getId(int r, int c) {
        return r * C + c; // [0, R * C)
    }
    
    int find(int u) {
        return parent[u] = parent[u] == u ? u : find(parent[u]);
    }

    int merge(int u, int v){
        u = find(u), v = find(v); // 3, 2
        if(u == v) {
            return sizes[u];
        }
        if(sizes[u] > sizes[v]) {
            swap(u, v);
        }
        parent[u] = v;
        sizes[v] += sizes[u];
        return sizes[v];
    }
    // [0, 2] [1] [3]
public:
    int largestIsland(vector<vector<int>>& grid) { // [[1,0],[0,1]]
        R = grid.size(); // 2
        C = grid[0].size(); // 2

        parent = vector<int>(R * C); // [2, 2, 2, 3]
        sizes = vector<int>(R * C, 1); // [1, 1, 3, 1]
        for(int i = 0; i < R * C; ++i) {
            parent[i] = i;
        }
        int ans = 1;
        for(int i = 0; i < R * C; ++i) { // i =1
            int r = i / C; // 0
            int c = i % R; // 1
            if(!grid[r][c]) {
                continue;
            }
            if(r < R - 1 && grid[r + 1][c]) {
                ans = max(ans, merge(i, getId(r + 1, c))); // merge(1, 3)
            }
            if(c < C - 1 && grid[r][c + 1]) {
                ans = max(ans, merge(i, getId(r, c + 1))); // merge(0, 1)
            }
        }
        for(int i = 0; i < R * C; ++i) {
            ans = max(ans, sizes[i]);
        }
        for(int i = 0; i < R * C; ++i) {
            int r = i / C;
            int c = i % R;
            
            if(grid[r][c]) {
                continue;
            }

            unordered_set<int> set;
            for(int j = 0; j < 4; ++j) {
                int nr = r + dr[j];
                int nc = c + dc[j];
                if(inRange(nr, nc) && grid[nr][nc]) {
                    set.insert(find(getId(nr, nc)));
                }
            }
            int tmpSize = 1;
            for(auto it : set) {
                tmpSize += sizes[it];
            }
            ans = max(ans, tmpSize);
        }

        return ans;
    }
};