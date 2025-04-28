class Solution {
    int R, C;
    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
    bool reveal(int r, int c, vector<vector<int>>& mineCountMap, vector<vector<char>>& board) {
        int cntMines = mineCountMap[r][c];
        if(cntMines > 0) {
            board[r][c] = cntMines + '0';
            return false;
        } else {
            board[r][c] = 'B';
            return true;
        }
    }
    void countMines(vector<vector<int>>& mineCountMap, vector<vector<char>>& board) {
        for(int r = 0; r < R; ++r) {
            for(int c = 0; c < C; ++c) {
                if(board[r][c] != 'M') {
                    continue;
                }
                for(int k = 0; k < 8; ++k) {
                    int nr = r + "00122210"[k] - '1';
                    int nc = c + "12221000"[k] - '1';
                    if(inRange(nr, nc)) {
                        mineCountMap[nr][nc]++;
                    }
                }
            }
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        this->R = board.size();
        this->C = board[0].size();
        vector<vector<int>> mineCountMap = vector<vector<int>>(R, vector<int>(C, 0));
        countMines(mineCountMap, board);
        queue<pair<int,int>> q;
        if(reveal(click[0], click[1], mineCountMap, board)) {
            q.push({click[0], click[1]});
        }
        while(!q.empty()) {
            auto [curR, curC] = q.front();
            q.pop();
            for(int i = 0; i < 8; ++i) {
                int nxtR = curR + "00122210"[i] - '1';
                int nxtC = curC + "12221000"[i] - '1';
                if(!inRange(nxtR, nxtC) || board[nxtR][nxtC] != 'E') {
                    continue;
                }
                if(reveal(nxtR, nxtC, mineCountMap, board)) {
                    q.push({nxtR, nxtC});
                }
            }
        }
        return board;
    }
};