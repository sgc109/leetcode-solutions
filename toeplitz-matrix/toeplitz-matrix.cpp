class Solution {
    int R, C;
    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
    bool check(int sr, int sc, vector<vector<int>>& matrix) {
        int r = sr, c = sc;
        int num = matrix[r][c];
        while(inRange(r, c)) {
            if(matrix[r][c] != num) return false;
            ++r, ++c;
        }
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        this->R = matrix.size();
        this->C = matrix[0].size();
        for(int i = 0; i < C; ++i) {
            if(!check(0, i, matrix)) return false;
        }
        for(int i = 1; i < R; ++i) {
            if(!check(i, 0, matrix)) return false;
        }
        return true;
    }
};
