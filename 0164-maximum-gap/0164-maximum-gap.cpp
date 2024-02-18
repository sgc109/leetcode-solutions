class Solution {
public:
    int maximumGap(vector<int>& nums) {
        long long base = 1;

        int maxVal = *max_element(begin(nums), end(nums));
        while(base <= maxVal) {
            vector<int> counter(10);
            for(int num : nums) {
                int digit = num / base % 10;
                counter[digit]++;
            }
            for(int i = 1; i < 10; ++i) {
                counter[i] += counter[i - 1];
            }
            vector<int> tmp(size(nums));
            for(int i = size(nums) - 1; i >= 0; --i) {
                int num = nums[i];
                int digit = num / base % 10;
                tmp[--counter[digit]] = num;
            }
            for(int i = 0; i < size(nums); ++i) {
                nums[i] = tmp[i];
            }
            base *= 10;
        }
        int ans = 0;
        for(int i = 0; i < size(nums) - 1; ++i) {
            ans = max(ans, nums[i + 1] - nums[i]);
        }
        return ans;
    }
};