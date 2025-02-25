class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if(nums.empty()) {
            return {{lower, upper}};
        }
        vector<vector<int>> ans;
        if(lower < nums[0]) {
            ans.push_back({lower, nums[0] - 1});
        }
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i + 1] - nums[i] > 1) {
                ans.push_back({nums[i] + 1, nums[i + 1] - 1});
            }
        }
        if(nums.back() < upper) {
            ans.push_back({nums.back() + 1, upper});
        }
        return ans;
    }
};