class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for(int num : nums) {
            counter[num]++;
        }
        
        vector<vector<int>> buckets = vector<vector<int>>(nums.size() + 1, vector<int>());
        for(auto it : counter) {
            buckets[it.second].push_back(it.first);
        }

        vector<int> ans;
        for(int i = nums.size(); i >= 1; --i) {
            if(ans.size() == k) {
                break;
            }
            for(int j = 0; j < buckets[i].size(); ++j) {
                ans.push_back(buckets[i][j]);
                if(ans.size() == k) {
                    break;
                }
            }
        }
        return ans;
    }
};