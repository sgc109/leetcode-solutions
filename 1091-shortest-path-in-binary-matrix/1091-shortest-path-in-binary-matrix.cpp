class Solution {
    int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int N;
    bool inRange(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }
public:
/*
0 1
1 0
OK

0 0 0
1 1 0
1 1 0

1 0 0
1 1 0
1 1 0

0 0 0 0
1 1 0 1
1 0 1 1
0 0 0 0

1 2 3 4
-1 -1 3 -1
-1 4 -1 -1
5 5 5 6

[(3, 1), (3, 0)]

0

1

grid:
0

dist:
-1

q: []
*/
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) { // 
        N = grid.size();
        if(grid[0][0]) {
            return -1;
        }
        if(N == 1) {
            return 1;
        }
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int r = cur.first.first; // 0
            int c = cur.first.second; // 1
            int dist = cur.second;

            for(int i = 0; i < 8; ++i) {
                int nr = r + dr[i]; // 1
                int nc = c + dc[i]; // 2
                if(!inRange(nr, nc) || grid[nr][nc]) {
                    continue;
                }
                if(nr == N - 1 && nc == N - 1) {
                    return dist + 1;
                }
                grid[nr][nc] = 1;
                q.push({{nr, nc}, dist + 1});
            }
        }
        return -1;
    }
};