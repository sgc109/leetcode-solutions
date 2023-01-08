class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, vector<int>> hashMap;
        
        for(int i = 0; i < cards.size(); ++i) {
            int num = cards[i];
            if(hashMap.count(num) == 0) {
                hashMap[num] = vector<int>();
            }
            hashMap[num].push_back(i);
        }
        int ans = cards.size() + 1;
        for(auto p : hashMap) {
            auto v = p.second;
            for(int i = 1; i < v.size(); ++i) {
                ans = min(ans, v[i] - v[i-1] + 1);
            }
        }
        
        return ans == cards.size() + 1 ? -1 : ans;
    }
};