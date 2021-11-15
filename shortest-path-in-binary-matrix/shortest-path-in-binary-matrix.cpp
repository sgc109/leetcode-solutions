class Solution {
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int N;
    
    bool in_range(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        N = grid.size();
        vector<vector<int>> dist = vector<vector<int>>(N, vector<int>(N, -1));
        queue<pair<int,int>> q;
        
        if(grid[0][0] == 1) return -1;
        
        q.push({0, 0});
        dist[0][0] = 1;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            for(int k = 0; k < 8; k++) {
                int r = cur.first + dy[k];
                int c = cur.second + dx[k];
                if(!in_range(r, c) || grid[r][c] == 1 || dist[r][c] != -1) continue;
                dist[r][c] = dist[cur.first][cur.second] + 1;
                q.push({r, c});
            }
        }
        
        return dist[N - 1][N - 1];
    }
};

// 