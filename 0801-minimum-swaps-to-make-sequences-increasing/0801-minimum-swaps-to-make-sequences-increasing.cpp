class Solution {
    int N;
    int dp[100003][2];

    int check(int pl, int pr, int l, int r, bool switched) {
        if(switched) {
            swap(pl, pr);
        }
        return pl < l && pr < r;
    }
public:
    int minSwap(vector<int> nums1, vector<int> nums2) {
        int N = nums1.size();
        memset(dp, 0x3c, sizeof(dp));

        dp[0][0] = 0;
        dp[0][1] = 1;

        for(int i = 1; i < N; ++i) {
            int pl = nums1[i - 1];
            int pr = nums2[i - 1];
            int cl = nums1[i];
            int cr = nums2[i];

            if(check(pl, pr, cl, cr, 0)) {
                dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            }
            if(check(pl, pr, cl, cr, 1)) {
                dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            }
            if(check(pl, pr, cr, cl, 0)) {
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
            }
            if(check(pl, pr, cr, cl, 1)) {
                dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
            }
        }

        return min(dp[N - 1][0], dp[N - 1][1]);
    }
};