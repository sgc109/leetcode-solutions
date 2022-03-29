class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> counts;
    for(int num : nums) {
      counts[num]++;
    }
    vector<pair<int,int>> pairs;
    for(auto entry : counts) {
      pairs.push_back({entry.second, entry.first});
    }
    sort(pairs.begin(), pairs.end(), greater<pair<int,int>>());
    vector<int> ret;
    for(int i = 0; i < k; ++i) {
      ret.push_back(pairs[i].second);
    }
    return ret;
  }
};
