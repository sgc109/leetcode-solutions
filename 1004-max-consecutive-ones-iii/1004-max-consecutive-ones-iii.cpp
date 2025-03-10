/*
1 <= len(nums) <= 10^5
0 <= k <= N
*/

class Solution {
public:
/*
nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 0
                            l
                                              r
ans = 10
*/
    int longestOnes(vector<int>& nums, int k) { // nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
        int ans = 0; // 0
        int l = 0;
        for(int r = 0; r < nums.size(); ++r) {
            if(nums[r] == 0) {
                --k;
            }
            while(k < 0) {
                if(nums[l] == 0) {
                    ++k;
                }
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};