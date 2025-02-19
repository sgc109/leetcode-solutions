class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                if(i > 0 && j > 0 && matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};