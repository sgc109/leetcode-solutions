class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        for(int i = 0; i < size(nums); ++i) {
            if(nums[i] >= k) {
                return i;
            }
        }
        return -1;
    }
};