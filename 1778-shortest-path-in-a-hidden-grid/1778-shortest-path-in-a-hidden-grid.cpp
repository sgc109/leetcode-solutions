/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
    unordered_map<char, pair<int,int>> offsets = {
        {'U', {-1, 0}},
        {'R', {0, 1}},
        {'D', {1, 0}},
        {'L', {0, -1}}
    };
    unordered_map<char, char> reverseDir = {
        {'U', 'D'},
        {'D', 'U'},
        {'L', 'R'},
        {'R', 'L'},
    };
    int grid[1003][1003];
    int dist[1003][1003];
    void dfs(int r, int c, GridMaster& master) {
        if(master.isTarget()) {
            grid[r][c] = 2;
        }
        for(auto [dir, offset] : offsets) {
            auto [dr, dc] = offset;
            int nr = r + dr;
            int nc = c + dc;
            if(grid[nr][nc] != -1) {
                continue;
            }
            if(master.canMove(dir)) {
                grid[nr][nc] = 1;
                master.move(dir);
                dfs(nr, nc, master);
                master.move(reverseDir[dir]);
            } else {
                grid[nr][nc] = 0;
            }
        }
    }
public:
    int findShortestPath(GridMaster &master) {
        // 1. build grid
        memset(grid, -1, sizeof(grid));
        grid[500][500] = 0;
        dfs(500, 500, master);

        // 2. BFS with grid
        memset(dist, -1, sizeof(dist));
        queue<pair<int,int>> q;
        q.push({500, 500});
        dist[500][500] = 0;
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int nr = r + "1201"[i] - '1';
                int nc = c + "2110"[i] - '1';
                if(dist[nr][nc] != -1) {
                    continue;
                }
                if(grid[nr][nc] == 0) {
                    continue;
                }
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
                if(grid[nr][nc] == 2) {
                    return dist[nr][nc];
                }
            }
        }
        return -1;
    }
};