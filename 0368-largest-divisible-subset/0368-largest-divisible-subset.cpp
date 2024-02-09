/*
Took: 34m 56s
Time: O(N^2)
Space: O(N^2)

*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> G = vector<vector<int>>(N, vector<int>());
        sort(begin(nums), end(nums));
        for(int i = 0; i < N; ++i) {
            for(int j = i + 1; j < N; ++j) {
                if(nums[j] % nums[i] == 0) {
                    G[i].push_back(j);
                }
            }
        }
        int ans = -1;
        int lastId;
        vector<int> longest = vector<int>(N, 0);
        vector<int> prev = vector<int>(N, -1);
        for(int i = 0; i < N; ++i) {
            if(ans < longest[i]) {
                ans = longest[i];
                lastId = i;
            }
            for(int nxt : G[i]) {
                if(longest[nxt] < longest[i] + 1) {
                    longest[nxt] = longest[i] + 1;
                    prev[nxt] = i;
                }
            }
        }

        vector<int> ret;
        int cur = lastId;
        ret.push_back(nums[lastId]);
        while(prev[cur] != -1) {
            cur = prev[cur];
            ret.push_back(nums[cur]);
        }

        return ret;
    }
};