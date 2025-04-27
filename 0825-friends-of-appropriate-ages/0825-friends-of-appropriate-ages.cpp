class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> counters(121, 0);
        for(auto age : ages) {
            counters[age]++;
        }
        vector<int> sortedAges;
        for(int i = 1; i <= 120; ++i) {
            for(int j = 0; j < counters[i]; ++j) {
                sortedAges.push_back(i);
            }
        }
        
        int l = 0;
        int ans = 0;
        for(int r = 0; r < sortedAges.size(); ++r) {
            while(l < r && sortedAges[l] <= 0.5 * sortedAges[r] + 7) {
                ++l;
            }
            ans += r - l;
            if(counters[sortedAges[r]] > 1 && sortedAges[r] > 0.5 * sortedAges[r] + 7) {
                ans += counters[sortedAges[r]] - 1;
                counters[sortedAges[r]]--;
            }
        }
        return ans;
    }
};