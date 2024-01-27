class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int R = mat.size();
        int C = mat[0].size();
        vector<int> colSum = vector<int>(C, 0);
        vector<int> rowSum = vector<int>(R, 0);
        
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                if(mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};