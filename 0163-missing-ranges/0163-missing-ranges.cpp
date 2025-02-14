class Solution {
public:
    // nums = []
    // lower = 1
    // upper = 10
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ret; // [[1,10]]
        if(nums.size() == 0) {
            ret.push_back({lower, upper});
            return ret;
        }
        if(lower < nums[0]) {
            ret.push_back({lower, nums[0] - 1});
        }

        int N = nums.size(); // 1
        for(int i = 0; i < N - 1; ++i) { // i = 0
            if(nums[i] < nums[i + 1] - 1) {
                ret.push_back({nums[i] + 1, nums[i + 1] - 1});
            }
        }
        if(nums.back() < upper) {
            ret.push_back({nums.back() + 1, upper});
        }

        return ret;
    }
};