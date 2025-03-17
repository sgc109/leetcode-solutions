class Solution {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int N;
    vector<vector<int>> grid;
    vector<vector<int>> labels;
    bool inRange(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }
    int dfs(int r, int c, int label) {
        int ret = 1; // 1
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!inRange(nr, nc) || !grid[nr][nc] || labels[nr][nc]) {
                continue;
            }
            labels[nr][nc] = label;
            ret += dfs(nr, nc, label);
        }
        return ret;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        this->N = grid.size();
        this->grid = grid;
        labels = vector<vector<int>>(N, vector<int>(N, 0));
        unordered_map<int, int> sizes;
        int ans = 1; // 1
        int seq = 1; // 3
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < N; ++c) {
                if(grid[r][c] && !labels[r][c]) {
                    labels[r][c] = seq;
                    sizes[seq] = dfs(r, c, seq);
                    ans = max(ans, sizes[seq]);
                    ++seq;
                }
            }
        }
/*
grid =
1 1
1 1

labels=
1 1
1 1

sizes = {1: 4}
*/
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < N; ++c) {
                if(grid[r][c]) {
                    continue;
                }
                set<int> uniqueLabels; // {1, 2}
                for(int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(!inRange(nr, nc) || !grid[nr][nc]) {
                        continue;
                    }
                    uniqueLabels.insert(labels[nr][nc]);
                }
                int mergedSize = 1; 
                for(int label : uniqueLabels) {
                    mergedSize += sizes[label];
                }
                ans = max(ans, mergedSize);
            }
        }
        return ans;
    }
};