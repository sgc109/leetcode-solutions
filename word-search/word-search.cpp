class Solution {
    int N, M;
    bool inRange(int row, int col) {
        return 0 <= row 
            && row < N 
            && 0 <= col 
            && col < M;
    }
    
    int toHash(int row, int col) {
        return row * 10 + col;
    }
    
    bool solve(
        int row, 
        int col, 
        int pos, 
        vector<vector<char>>& board, 
        string& word
    ) {
        if(pos == word.size()) return true;
        if(!inRange(row, col) 
           || board[row][col] != word[pos] ) {
            return false;
        }
        char backup = board[row][col];
        board[row][col] = 0;
        for(int i = 0; i < 4; i++) {
            int nr = row + "2110"[i] - '1';
            int nc = col + "1201"[i] - '1';
            if(solve(nr, nc, pos + 1, board, word)) return true;
        }
        board[row][col] = backup;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->N = board.size();
        this->M = board[0].size();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(solve(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};