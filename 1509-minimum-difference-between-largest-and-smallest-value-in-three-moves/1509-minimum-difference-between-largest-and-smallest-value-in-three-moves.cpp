class Solution {
public:
    int minDifference(vector<int>& nums) {
        int N = nums.size();
        if(N <= 4) {
            return 0;
        }
        sort(begin(nums), end(nums));
        int ans = 2e9 + 1;
        for(int i = 0; i < 4; ++i) {
            int diff = nums[N - 4 + i] - nums[i];
            ans = min(ans, diff);
        }
        return ans;
    }
};