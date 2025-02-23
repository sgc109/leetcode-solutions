class Solution {
public:
    void nextPermutation(vector<int>& nums) { // [5 4 1 2 2]
        int breaker = -1; // 1                        ^ ^ ^
        for(int i = nums.size() - 2; i >= 0; --i) {
            if(nums[i] < nums[i + 1]) {
                breaker = i;
                break;
            }
        }
        if(breaker != -1) {
            for(int i = nums.size() - 1; i > breaker; --i) {
                if(nums[breaker] < nums[i]) {
                    swap(nums[breaker], nums[i]);
                    break;
                }
            }
        }
        int pos = 0;
        while(breaker + 1 + pos < nums.size() - 1 - pos) {
            swap(nums[breaker + 1 + pos], nums[nums.size() - 1 - pos]);
            ++pos;
        }
        // 5 4 1 2 2
    }
};

