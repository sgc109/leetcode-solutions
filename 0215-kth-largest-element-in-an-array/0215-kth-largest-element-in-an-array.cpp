class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int lo = 20001, hi = -1;
        for(int& num : nums) {
            num += 10000;
            lo = min(lo, num);
            hi = max(hi, num);
        }

        k = size(nums) - k + 1;

        while(lo < hi) {
            int mid = (lo + hi) / 2;
            
            int count = 0;
            for(int num : nums) {
                count += num <= mid;
            }

            if(count < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return lo - 10000;
    }
};