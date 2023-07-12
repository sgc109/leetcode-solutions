class Solution {
    int minLen[100003];
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        memset(minLen, 0x3c, sizeof(minLen));
        int acc = 0;

        int N = arr.size();
        unordered_map<int, int> um;
        int ans = N + 1;
        um[0] = -1;
        for(int i = 0; i < N; ++i) {
            if(i > 0) {
                minLen[i] = minLen[i-1];
            }
            acc += arr[i];
            if(um.count(acc - target) > 0) {
                printf("i: %d\n", i);
                int len = i - um[acc - target];
                if(um[acc - target] > -1) {
                    ans = min(ans, minLen[um[acc - target]] + len);
                }
                minLen[i] = min(minLen[i], len);
            }
            um[acc] = i;
        }

        return ans == N + 1 ? -1 : ans;
    }
};