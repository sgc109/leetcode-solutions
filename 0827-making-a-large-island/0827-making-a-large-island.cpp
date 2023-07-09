class Solution {
    int N;
    int visited[503][503];
    int groupId[503][503];
    int groupSize[250003];
    
    int dy[4] = {0, -1, 1, 0};
    int dx[4] = {-1, 0, 0, 1};
    
    bool inRange(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }
    
    int dfs(int r, int c, int newId, vector<vector<int>>& grid) {
        if(!inRange(r, c) || visited[r][c] || grid[r][c] == 0) {
            return 0;
        }
        visited[r][c] = 1;
        groupId[r][c] = newId;
        
        int size = 1;
        for(int k = 0; k < 4; ++k) {
            int nr = r + dy[k];
            int nc = c + dx[k];
            size += dfs(nr, nc, newId, grid);
        }
        
        return size;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size();
  
        int groupCounter = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(grid[i][j] == 0 || visited[i][j]) {
                    continue;
                }
                vector<pair<int,int>> cells;
                int size = dfs(i, j, groupCounter, grid);
                groupSize[groupCounter++] = size;
            }
        }
        
        if(groupCounter == 0) {
            return 1;
        }
        
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(grid[i][j] == 1) {
                    continue;
                }
                unordered_set<int> adjGroupIds;
                for(int k = 0; k < 4; ++k) {
                    int ni = i + dy[k];
                    int nj = j + dx[k];
                    if(!inRange(ni, nj) || grid[ni][nj] == 0) {
                        continue;
                    }
                    adjGroupIds.insert(groupId[ni][nj]);
                }
                int sum = 1;
                for(auto grp : adjGroupIds) {
                    sum += groupSize[grp];
                }
                ans = max(ans, sum);
            }
        }
        
        return ans == 0 ? N * N : ans;
    }
};