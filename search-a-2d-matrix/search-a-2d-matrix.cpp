class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size();
        int C = matrix[0].size();
        int lo = 0, hi = R * C - 1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int r = mid / C;
            int c = mid % C;
            if(matrix[r][c] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return matrix[lo / C][lo % C] == target;
    }
};