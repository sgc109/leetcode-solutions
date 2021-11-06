class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        bool bigger = false;
        while(l < r) {
            if((bigger && nums[l] < nums[r]) ||
              (!bigger && nums[l] > nums[r])) {
                swap(nums[l], nums[r]);
            }
            ++l;
            bigger = !bigger;
        }
    }
};
