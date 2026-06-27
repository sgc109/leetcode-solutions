/*
rowSum = [0,4,10]
            ^
colSum = [0,6,8]
            ^

5
3 4
  2 8



*/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int R = rowSum.size();
        int C = colSum.size();
        vector<vector<int>> ans = vector<vector<int>>(R, vector<int>(C));
        int i = 0;
        int j = 0;
        while(i < R && j < C) {
            ans[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];
            if(rowSum[i] == 0) {
                ++i;
            }
            if(colSum[j] == 0) {
                ++j;
            }
        }
        return ans;
    }
};