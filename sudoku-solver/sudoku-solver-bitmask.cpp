class Solution {
    int rowSet[9], colSet[9], boxSet[3][3];
    int bitOn(int org, int pos) {
        return org |= (1 << pos);
    }
    int bitOff(int org, int pos) {
        return org &= ~(1 << pos);
    }
    int isBitOn(int org, int pos) {
        return (org >> pos) & 1;
    }
    void insert(int row, int col, int num, vector<vector<char>>& board) {
        rowSet[row] = bitOn(rowSet[row], num);
        colSet[col] = bitOn(colSet[col], num);
        boxSet[row / 3][col / 3] = bitOn(boxSet[row / 3][col / 3], num);
        board[row][col] = num + '0';
    }
    void erase(int row, int col, int num, vector<vector<char>>& board) {
        rowSet[row] = bitOff(rowSet[row], num);
        colSet[col] = bitOff(colSet[col], num);
        boxSet[row / 3][col / 3] = bitOff(boxSet[row / 3][col / 3], num);
        board[row][col] = '.';
    }
    bool exist(int row, int col, int num) {
        return isBitOn(rowSet[row], num)
          || isBitOn(colSet[col], num)
          || isBitOn(boxSet[row / 3][col / 3], num);
    }
    bool solve(int row, int col, vector<vector<char>>& board) {
        if(col == 9) return solve(row + 1, 0, board);
        if(row == 9) return true;
        if(board[row][col] != '.') return solve(row, col + 1, board);
        for(int i = 1; i <= 9; i++) {
            if(exist(row, col, i)) continue;
            insert(row, col, i, board);
            bool ret = solve(row, col + 1, board);
            if(ret) return true;
            erase(row, col, i, board);
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] != '.') {
                    insert(i, j, board[i][j] - '0', board);
                }
            }
        }
        bool ret = solve(0, 0, board);
        assert(ret);
    }
};
