class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(nums[l] <= nums[m]) { // 왼쪽 절반이 정렬
                if(nums[l] <= target && target <= nums[m]) r = m;
                else l = m + 1;
            } else { // 오른쪽 절반이 정렬
                if(nums[m] <= target && target <= nums[r]) l = m;
                else r = m - 1;
            }
        }
        if(nums[l] == target) return l;
        return -1;
    }
};