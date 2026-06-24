class Solution {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    vector<vector<bool>> visited;
    vector<vector<int>> heights;
    int R, C;
    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
    bool dfs(int r, int c, int cap) {
        if(r == R - 1 && c == C - 1) {
            return true;
        }
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!inRange(nr, nc) || visited[nr][nc] || abs(heights[r][c] - heights[nr][nc]) > cap) {
                continue;
            }
            visited[nr][nc] = true;
            bool ans = dfs(nr, nc, cap);
            if(ans) {
                return true;
            }
        }
        return false;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        this->R = heights.size();
        this->C = heights[0].size();
        this->heights = heights;
        int lo = 0;
        int hi = 1e6 + 1;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            this->visited = vector<vector<bool>>(R, vector<bool>(C, false));
            visited[0][0] = true;
            bool reachable = dfs(0, 0, mid);
            if(reachable) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};