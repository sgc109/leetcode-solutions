class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> counts;
    for(int num : nums) {
      counts[num]++;
    }
    vector<vector<int>> buckets(nums.size() + 1, vector<int>());
    for(auto p : counts) {
      buckets[p.second].push_back(p.first);
    }
    vector<int> ret;
    for(int i = nums.size(); i >= 1; --i) {
      if(ret.size() == k) break;
      for(auto num : buckets[i]) {
        ret.push_back(num);
        if(ret.size() == k) break;
      }
    }
    return ret;
  }
};
