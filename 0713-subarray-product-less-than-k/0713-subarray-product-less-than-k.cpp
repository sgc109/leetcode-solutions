class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int N = size(nums);
        int l = 0;
        int product = 1;
        int ans = 0;
        for(int r = 0; r < N; ++r) {
            product *= nums[r];
            if(product < k) {
                ans += r - l + 1;
            } else {
                while(product >= k && l < r + 1) {
                    product /= nums[l++];
                }
                ans += r - l + 1;
            }
        }
        return ans;
    }
};