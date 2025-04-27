class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> counters;
        for(auto age : ages) {
            counters[age]++;
        }
        sort(begin(ages), end(ages));
        int l = 0;
        int ans = 0;
        for(int r = 0; r < ages.size(); ++r) {
            while(l < r && ages[l] <= 0.5 * ages[r] + 7) {
                ++l;
            }
            ans += r - l;
            if(counters[ages[r]] > 1 && ages[r] > 0.5 * ages[r] + 7) {
                ans += counters[ages[r]] - 1;
                counters[ages[r]]--;
            }
        }
        return ans;
    }
};