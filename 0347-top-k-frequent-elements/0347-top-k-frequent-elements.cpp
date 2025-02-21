class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for(int num : nums) {
            counter[num]++;
        }
        vector<vector<int>> buckets(nums.size() + 1, vector<int>());
        for(auto it : counter) {
            buckets[it.second].push_back(it.first);
        }

        vector<int> ans;
        for(int i = nums.size(); i >= 1 && ans.size() < k; --i) {
            for(int num : buckets[i]) {
                ans.push_back(num);
            }
            if(ans.size() == k) {
                break;
            }
        }
        return ans;
    }
};