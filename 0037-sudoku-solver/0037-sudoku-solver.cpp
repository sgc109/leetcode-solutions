class Solution {
    vector<vector<int>> hori;
    vector<vector<int>> vert;
    vector<vector<int>> sqrs;
    bool go(int r, int c, vector<vector<char>>& board) {
        if(r == 9) return true;
        if(c == 9) return go(r + 1, 0, board);
        if(board[r][c] != '.') return go(r, c + 1, board);
        for(int i = 0; i < 9; ++i) {
            if(hori[r][i]) continue;
            if(vert[c][i]) continue;
            if(sqrs[r/3 * 3 + c/3][i]) continue;
            hori[r][i] = 1;
            vert[c][i] = 1;
            sqrs[r/3 * 3 + c/3][i] = 1;
            board[r][c] = '1' + i;
            if(go(r, c + 1, board)) return true;
            board[r][c] = '.';
            hori[r][i] = 0;
            vert[c][i] = 0;
            sqrs[r/3 * 3 + c/3][i] = 0;
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        this->hori = vector<vector<int>>(9, vector<int>(9, 0));
        this->vert = vector<vector<int>>(9, vector<int>(9, 0));
        this->sqrs = vector<vector<int>>(9, vector<int>(9, 0));
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                hori[i][num] = 1;
                vert[j][num] = 1;
                sqrs[i/3 * 3 + j/3][num] = 1;
            }
        }
        go(0, 0, board);
    }
};