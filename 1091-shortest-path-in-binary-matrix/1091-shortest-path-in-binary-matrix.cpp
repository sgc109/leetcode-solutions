class Solution {
    int R;
    int C;
    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
    /*
    
    8 1 2
    7 0 3
    6 5 4

0 1
1 0

    */
    int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        this->R = grid.size(); // 2
        this->C = grid[0].size(); // 2
        if(grid[0][0] == 1 || grid.back().back() == 1) {
            return -1;
        }
        vector<vector<int>> dist = vector<vector<int>>(R, vector<int>(C, -1));
        queue<pair<int,int>> q; // []
        q.push({0, 0});
        dist[0][0] = 1;
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            int curR = front.first;
            int curC = front.second;
            if(curR == R - 1 && curC == C - 1) {
                return dist[curR][curC];
            }
            for(int i = 0; i < 8; ++i) {
                int nextR = curR + dr[i];
                int nextC = curC + dc[i];
                if(!inRange(nextR, nextC) || grid[nextR][nextC] || dist[nextR][nextC] != -1) {
                    continue;
                }
                dist[nextR][nextC] = dist[curR][curC] + 1;
                q.push({nextR, nextC});
            }
        }
        return -1;
    }
};