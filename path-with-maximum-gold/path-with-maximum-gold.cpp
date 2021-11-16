class Solution {
    int R, C;
    vector<vector<bool>> visited;
    vector<vector<int>> grid;
    
    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
    
    int dfs(int r, int c) {
        if(!inRange(r, c) || visited[r][c] || grid[r][c] == 0) return 0;
        visited[r][c] = true;
        int ret = 0;
        ret = max(ret, dfs(r-1, c));
        ret = max(ret, dfs(r+1, c));
        ret = max(ret, dfs(r, c-1));
        ret = max(ret, dfs(r, c+1));
        visited[r][c] = false;
        return ret + grid[r][c];
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        this->grid = grid;
        visited = vector<vector<bool>>(R, vector<bool>(C, false));
        int ans = 0;
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};