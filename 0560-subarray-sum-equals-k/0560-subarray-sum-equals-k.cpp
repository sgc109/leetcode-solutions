class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> psumCounter;
        psumCounter[0] = 1;
        int acc = 0;
        int ans = 0;
        for(int num : nums) {
            acc += num;
            ans += psumCounter[acc - k];
            psumCounter[acc]++;
        }
        return ans;
    }
};