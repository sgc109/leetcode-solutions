class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int N = nums.size();
        int l = 0;
        for(int r = 0; r < N; ++r) {
            if(!nums[r]) {
                continue;
            }
            while(l < N && nums[l]) {
                ++l;
            }
            if(l < r) {
                nums[l] = nums[r];
                nums[r] = 0;
            }
        }
    }
};