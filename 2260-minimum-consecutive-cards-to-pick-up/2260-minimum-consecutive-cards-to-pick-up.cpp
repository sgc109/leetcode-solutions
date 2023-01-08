class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastIdx;
        
        int ans = cards.size() + 1;
        for(int i = 0; i < cards.size(); ++i) {
            int num = cards[i];
            if(lastIdx.count(num) != 0) {
                ans = min(ans, i - lastIdx[num] + 1);
            }
            lastIdx[num] = i;
        }
        
        return ans == cards.size() + 1 ? -1 : ans;
    }
};