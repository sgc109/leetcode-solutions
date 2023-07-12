class Solution {
    int length[100003];

public:
    int minSumOfLengths(vector<int>& arr, int target) {
        memset(length, 0x3c, sizeof(length));

        int N = arr.size();
        int ans = N + 1;
        int sum = 0;
        int r = 0;
        int prevMinLen = N + 1;
        for(int l = 0; l < N; ++l) {
            while(r < N && sum < target) {
                sum += arr[r];
                ++r;
            }
            if(sum == target) {
                ans = min(ans, prevMinLen + r - l);
                length[r - 1] = r - l;
            }
            prevMinLen = min(prevMinLen, length[l]);
            sum -= arr[l];
        }

        return ans == N + 1 ? -1 : ans;
    }
};


/*

a + x
a + 2x


*/