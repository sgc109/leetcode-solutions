class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(begin(nums), end(nums), target) - begin(nums);
        int r = upper_bound(begin(nums), end(nums), target) - begin(nums);
        vector<int> ans;
        if(l == nums.size() || nums[l] != target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(l);
        ans.push_back(r - 1);
        return ans;
    }
};