using namespace std;

class Solution {
    const int INF = 987654321;
    
    vector<priority_queue<int>> maxRows, maxCols;
    
    int R, C;
    
    struct Cell {
        int num, r, c;
        
        bool operator<(const Cell& rhs) const {
            return num < rhs.num;
        }
        
        bool operator>(const Cell& rhs) const {
            return num > rhs.num;
        }
        
        
    };
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        R = size(mat);
        C = size(mat[0]);
        maxRows = vector<priority_queue<int>>(R, priority_queue<int>());
        maxCols = vector<priority_queue<int>>(C, priority_queue<int>());
        
        vector<Cell> cells;
        int prv = INF;
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                cells.emplace_back(mat[i][j], i, j);
            }
        }
        sort(begin(cells), end(cells), greater<Cell>());
        int ret = 1;
        vector<pair<Cell, int>> buffer;
        for(int i = 0; i < cells.size(); ++i) {
            if(i > 0 && cells[i-1].num != cells[i].num) {
                for(auto p : buffer) {
                    auto cell = p.first;
                    auto ans = p.second;
                    maxRows[cell.r].push(ans);
                    maxCols[cell.c].push(ans);
                }
                buffer.clear();
            }
            auto cell = cells[i];
            int ans = 1;
            if(maxRows[cell.r].size() > 0) {
                ans = max(ans, 1 + maxRows[cell.r].top());
            }
            if(maxCols[cell.c].size() > 0) {
                ans = max(ans, 1 + maxCols[cell.c].top());
            }
            ret = max(ret, ans);
            buffer.emplace_back(cell, ans);
        }
        return ret;
    }
};