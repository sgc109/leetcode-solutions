class Solution {
    int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int N;
    bool inRange(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        N = grid.size();
        vector<vector<int>> dist = vector<vector<int>>(N, vector<int>(N, -1));
        if(grid[0][0]) {
            return -1;
        }
        if(N == 1) {
            return 1;
        }
        dist[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int r = cur.first;
            int c = cur.second;

            for(int i = 0; i < 8; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(!inRange(nr, nc) || grid[nr][nc] || dist[nr][nc] != -1) {
                    continue;
                }
                dist[nr][nc] = dist[r][c] + 1;
                if(nr == N - 1 && nc == N - 1) {
                    return dist[nr][nc];
                }
                q.push({nr, nc});
            }
        }
        return -1;
    }
};