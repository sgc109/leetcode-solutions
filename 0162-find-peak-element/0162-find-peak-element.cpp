/*

1 0 1
-1 0 -1
-1 0 1
1 0 -1

*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            int l = (mid == 0 || nums[mid - 1] < nums[mid]) ? -1 : 1;
            int r = (mid == nums.size() - 1 || nums[mid] < nums[mid + 1]) ? 1 : -1;
            if(l == -1 && r == -1) {
                return mid;
            } else if(l == 1 && r == 1) {
                lo = mid + 1;
            } else if(l == -1 && r == 1) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};