/*
Took: 34m 56s
Time: O(N^2)
Space: O(N)

*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        sort(begin(nums), end(nums));
        int ans = -1;
        int lastId;
        vector<int> longest = vector<int>(N, 0);
        vector<int> prev = vector<int>(N, -1);
        for(int i = 0; i < N; ++i) {
            if(ans < longest[i]) {
                ans = longest[i];
                lastId = i;
            }
            for(int j = i + 1; j < N; ++j) {
                if(nums[j] % nums[i] != 0) {
                    continue;
                }
                if(longest[j] < longest[i] + 1) {
                    longest[j] = longest[i] + 1;
                    prev[j] = i;
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