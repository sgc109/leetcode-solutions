class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int N = hours.size();

        int cntHap = 0;
        int cntUnh = 0;
        int ans = 0;

        unordered_map<int, int> index;
        index[0] = -1;
        for(int i = 0; i < N; ++i) {
            if(hours[i] > 8) {
                cntHap++;
            } else {
                cntUnh++;
            }
            int diff = cntHap - cntUnh;
            if(diff > 0) {
                ans = i + 1;
            }

            if(index.count(diff) == 0) {
                index[diff] = i;
            }

            if(index.count(diff - 1) != 0) {
                ans = max(ans, i - index[diff - 1]);
            }
        }
        return ans;
    }
};