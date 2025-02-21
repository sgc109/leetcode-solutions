/*
1 <= len(nums) <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= len(nums)
always unique answer
any order


*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for(int num : nums) {
            counter[num]++;
        }
        vector<pair<int, int>> freqToNum;
        for(auto it : counter) {
            freqToNum.push_back({it.second, it.first});
        }
        sort(freqToNum.begin(), freqToNum.end());
        vector<int> ans;
        for(int i = 0; i < k; ++i) {
            ans.push_back(freqToNum[freqToNum.size() - 1 - i].second);
        }

        return ans;
    }
};