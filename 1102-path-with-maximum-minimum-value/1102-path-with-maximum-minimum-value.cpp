/*
Took: 22m 6s
Time: O(m * n * log(m * n))
Space: O(m * n)
*/

class Solution {
    struct Cell {
        int val;
        int r, c;
        bool operator<(const Cell& rhs) const {
            return val > rhs.val;
        }
    };

    int dy[4] = {0, -1, 1, 0};
    int dx[4] = {-1, 0, 0, 1};

    int R, C;
    vector<int> par;
    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        par[a] = b;
    }
    int getId(int r, int c) {
        return r * C + c;
    }
    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        par = vector<int>(R * C);
        for(int i = 0; i < R * C; ++i) {
            par[i] = i;
        }

        vector<Cell> cells;
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                cells.push_back(Cell{grid[i][j], i, j});
            }
        }
        sort(begin(cells), end(cells));
        
        for(int i = 0; i < cells.size(); ++i) {
            auto cell = cells[i];
            for(int k = 0; k < 4; ++k) {
                int nr = cell.r + dy[k];
                int nc = cell.c + dx[k];
                if(!inRange(nr, nc) || grid[nr][nc] < cell.val) {
                    continue;
                }
                merge(getId(cell.r, cell.c), getId(nr, nc));
            }
            if(find(getId(0, 0)) == find(getId(R - 1, C - 1))) {
                return cell.val;
            }
        }
        return -1; // cannot reach
    }
};