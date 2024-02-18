class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int ans = 0;
        for(int i = 0; i < size(nums) - 1; ++i) {
            ans = max(ans, nums[i + 1] - nums[i]);
        }
        return ans;
    }
};