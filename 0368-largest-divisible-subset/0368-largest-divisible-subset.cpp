class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> G = vector<vector<int>>(N, vector<int>());
        vector<int> in = vector<int>(N, 0);
        sort(begin(nums), end(nums));
        for(int i = 0; i < N; ++i) {
            for(int j = i + 1; j < N; ++j) {
                if(nums[j] % nums[i] == 0) {
                    G[i].push_back(j);
                    ++in[j];
                }
            }
        }
        int ans = 0;
        int lastId;
        vector<int> longest = vector<int>(N, 0);
        vector<int> prev = vector<int>(N);
        queue<int> q;
        for(int i = 0; i < N; ++i) {
            if(in[i] == 0) {
                q.push(i);
                longest[i] = 1;
                prev[i] = i;
            }
        }
        while(q.size() > 0) {
            int cur = q.front();
            q.pop();
            if(ans < longest[cur]) {
                ans = longest[cur];
                lastId = cur;
            }
            for(int nxt : G[cur]) {
                --in[nxt];
                if(longest[nxt] < longest[cur] + 1) {
                    longest[nxt] = longest[cur] + 1;
                    prev[nxt] = cur;
                }
                if(in[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        vector<int> ret;
        int cur = lastId;
        ret.push_back(nums[lastId]);
        while(prev[cur] != cur) {
            cur = prev[cur];
            ret.push_back(nums[cur]);
        }

        return ret;
    }
};