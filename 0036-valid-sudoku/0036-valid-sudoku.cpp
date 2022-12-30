class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i) {
            vector<int> check(9, 0);
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;
                int idx = board[i][j] - '1';
                if(check[idx]) return false;
                check[idx] = 1;
            }
        }
        for(int i = 0; i < 9; ++i) {
            vector<int> check(9, 0);
            for(int j = 0; j < 9; ++j) {
                if(board[j][i] == '.') continue;
                int idx = board[j][i] - '1';
                if(check[idx]) return false;
                check[idx] = 1;
            }
        }
        for(int i = 0; i < 9; ++i) {
            vector<int> check(9, 0);
            for(int j = 0; j < 9; ++j) {
                int r = i / 3 * 3 + j / 3;
                int c = i % 3 * 3 + j % 3;
                if(board[r][c] == '.') continue;
                int idx = board[r][c] - '1';
                if(check[idx]) return false;
                check[idx] = 1;
            }
        }
        return true;
    }
};