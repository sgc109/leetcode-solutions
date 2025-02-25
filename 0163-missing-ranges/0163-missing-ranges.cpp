class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if(nums.empty()) {
            return {{lower, upper}};
        }
        int prev = lower - 1;
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i) {
            if(prev + 1 <= nums[i] - 1) {
                ans.push_back({prev + 1, nums[i] - 1});
            }
            prev = nums[i];
        }
        if(prev + 1 <= upper) {
            ans.push_back({prev + 1, upper});
        }
        return ans;
    }
};