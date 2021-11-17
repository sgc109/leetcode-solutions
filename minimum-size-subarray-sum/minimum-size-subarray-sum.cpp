class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r;
        int sum = 0;
        int ans = nums.size() + 1;
        for(int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while(sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }
        }
        if(ans == nums.size() + 1) return 0;
        return ans;
    }
};