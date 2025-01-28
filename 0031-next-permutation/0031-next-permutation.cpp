class Solution {
    void swapRange(vector<int>& nums, int l, int r) {
        int len = r - l + 1;
        for(int i = 0; i < len / 2; ++i) {
            swap(nums[l + i], nums[r - i]);
        }
    }
public:
    void nextPermutation(vector<int>& nums) {
        int l = -1; // 0
        for(int i = size(nums) - 1; i >= 1; --i) {
            if(nums[i - 1] < nums[i]) {
                l = i - 1;
                break;
            }
        }
        if(l == -1) {
            swapRange(nums, 0, size(nums) - 1);
            return;
        }

        int firstSameOrLess = size(nums);
        for(int i = l + 1; i < size(nums); ++i) {
            if(nums[l] >= nums[i]) {
                firstSameOrLess = i;
                break;
            }
        }
        int nextIdx = firstSameOrLess - 1;
        swap(nums[l], nums[nextIdx]);
        swapRange(nums, l + 1, size(nums) - 1);
    }
};