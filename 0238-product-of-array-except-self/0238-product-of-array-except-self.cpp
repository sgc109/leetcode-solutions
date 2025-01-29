class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cntZeros = 0;
        int productExceptZero = 1;

        for(int num : nums) {
            if(num == 0) {
                ++cntZeros;
            } else {
                productExceptZero *= num;
            }
        }

        if(cntZeros > 1) {
            return vector<int>(size(nums), 0);
        }

        vector<int> ans(size(nums));
        if(cntZeros == 0) {
            for(int i = 0; i < size(nums); ++i) {
                ans[i] = productExceptZero / nums[i];
            }
            return ans;
        }

        // There is 1 zero
        for(int i = 0; i < size(ans); ++i) {
            if(nums[i] != 0) {
                ans[i] = 0;
            } else {
                ans[i] = productExceptZero;
            }
        }
        return ans;
    }
};