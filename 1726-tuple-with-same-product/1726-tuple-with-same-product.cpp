class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        map<int, int> counter;
        
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                counter[nums[i] * nums[j]]++;
            }
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                int cnt = counter[nums[i] * nums[j]];
                ans += (cnt - 1) * 4;
            }
        }
              
        return ans;
    }
};