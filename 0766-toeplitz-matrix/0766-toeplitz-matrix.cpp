class Solution {
    int R, C;
    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
    bool isPoss(int sr, int sc, vector<vector<int>>& matrix) {
        int cr = sr;
        int cc = sc;
        int val = -1;
        while(inRange(cr, cc)) {
            if(val == -1) {
                val = matrix[cr][cc];
            } else if(val != matrix[cr][cc]) {
                return false;
            }
            cr++;
            cc++;
        }
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        R = matrix.size();
        C = matrix[0].size();
        for(int i = 0; i < C; ++i) {
            if(!isPoss(0, i, matrix)) {
                return false;
            }
        }
        for(int i = 1; i < R; ++i) {
            if(!isPoss(i, 0, matrix)) {
                return false;
            }
        }
        return true;
    }
};