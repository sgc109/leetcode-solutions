class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        int cnt = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i-1] >= nums[i]) {
                ans = max(ans, cnt);
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};