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
    unordered_map<int, unordered_map<int,int>> grid;
    void dfs(int r, int c, GridMaster& master) {
        if(master.isTarget()) {
            grid[r][c] = 2;
        }
        for(auto [dir, offset] : offsets) {
            auto [dr, dc] = offset;
            int nr = r + dr;
            int nc = c + dc;
            if(grid.count(nr) > 0 && grid[nr].count(nc) > 0) {
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
        grid[0][0] = -1;
        dfs(0, 0, master);

        // 2. BFS with grid
        queue<pair<int,int>> q;
        unordered_map<int, unordered_map<int, int>> dist;
        q.push({0, 0});
        dist[0][0] = 0;
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int nr = r + "1201"[i] - '1';
                int nc = c + "2110"[i] - '1';
                if(dist.count(nr) > 0 && dist[nr].count(nc) > 0) {
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