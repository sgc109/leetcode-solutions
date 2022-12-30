class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for(int num : nums) {
            count[num]++;
        }
        int idx = 0;
        for(int i = 0; i < nums.size(); ++i) {
            while(count[idx] == 0) {
                idx++;
            }
            count[idx]--;
            nums[i] = idx;
        }
    }
};