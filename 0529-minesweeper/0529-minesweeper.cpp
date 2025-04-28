class Solution {
    int R, C;
    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
    int countMines(int r, int c, vector<vector<char>>& board) {
        int ret = 0;
        for(int i = 0; i < 8; ++i) {
            int nr = r + "00122210"[i] - '1';
            int nc = c + "12221000"[i] - '1';
            if(inRange(nr, nc) && board[nr][nc] == 'M') {
                ++ret;
            }
        }
        return ret;
    }
    bool reveal(int r, int c, vector<vector<char>>& board) {
        int cntMines = countMines(r, c, board);
        if(cntMines > 0) {
            board[r][c] = cntMines + '0';
            return false;
        } else {
            board[r][c] = 'B';
            return true;
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
        queue<pair<int,int>> q;
        if(reveal(click[0], click[1], board)) {
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
                if(reveal(nxtR, nxtC, board)) {
                    q.push({nxtR, nxtC});
                }
            }
        }
        return board;
    }
};