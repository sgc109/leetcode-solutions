class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> counter;
        
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                int cnt = counter[nums[i] * nums[j]];
                ans += cnt * 8;
                counter[nums[i] * nums[j]]++;
            }
        }
              
        return ans;
    }
};