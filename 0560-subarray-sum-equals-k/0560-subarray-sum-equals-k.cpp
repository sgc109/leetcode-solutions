/*

[[1 2 3] 4 5] 6 

cur_sum - prev_sum = k
cur_sum - k = prev_sum

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;

        int ans = 0;
        int acc = 0;
        for(int i = 0; i < size(nums); ++i) {
            acc += nums[i];
            ans += map[acc - k];
            map[acc]++;
        }

        return ans;
    }
};