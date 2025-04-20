class Solution {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int R;
    int C;
    vector<vector<char>> board;
    string word;
    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }

    bool check(int r, int c, int idx) {
        if(board[r][c] != word[idx]) {
            return false;
        }
        if(idx == word.size() - 1) {
            return true;
        }
        char backup = board[r][c];
        board[r][c] = '!';
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!inRange(nr, nc) || board[nr][nc] == '!') {
                continue;
            }
            if(check(nr, nc, idx + 1)) {
                return true;
            }
        }
        board[r][c] = backup;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        this->R = board.size();
        this->C = board[0].size();
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                if(check(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};