class Solution {
    int quickSelect(int l, int r, int k, vector<int>& nums) {
        int randomIdx = rand() % (r - l + 1) + l;
        swap(nums[randomIdx], nums[r]);
        int p = l;
        for(int i = l; i < r; ++i) {
            int couldBeSame = rand() % 2;
            if((couldBeSame && nums[i] <= nums[r]) ||
               (!couldBeSame && nums[i] < nums[r])) {
                swap(nums[p], nums[i]);
                ++p;
            }
        }
        swap(nums[p], nums[r]);
        if(p == k) {
            return nums[p];
        } else if(p < k) {
            return quickSelect(p + 1, r, k, nums);
        } else {
            return quickSelect(l, p - 1, k, nums);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickSelect(0, nums.size() - 1, k, nums);
    }
};