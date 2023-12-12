class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> counter;
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                int multiple = nums[i] * nums[j];
                ans += counter[multiple];
                counter[multiple]++;
            }
        }
        return ans * 8;
    }
};