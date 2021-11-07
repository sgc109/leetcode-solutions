class Solution {
    int lower(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while(lo < hi) {
            int mid = lo + (hi-lo) / 2;
            if(nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower(nums, target);
        int r = lower(nums, target + 1) - 1;
        if(l == nums.size() || nums[l] != target) {
            return vector<int>({-1, -1});
        }
        return vector<int>({l, r});
    }
};
