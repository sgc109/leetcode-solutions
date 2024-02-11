class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        vector<vector<int>> ret = vector<vector<int>>(R, vector<int>(C, 0));
        for(int i = 0; i < C; ++i) {
            int maxVal = -1;
            for(int j = 0; j < R; ++j) {
                maxVal = max(maxVal, matrix[j][i]);
            }
            for(int j = 0; j < R; ++j) {
                if(matrix[j][i] == -1) {
                    ret[j][i] = maxVal;
                } else {
                    ret[j][i] = matrix[j][i];
                }
            }
        }
        return ret;
    }
};