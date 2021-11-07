class Solution {
    bool isPoss(int x, int n, vector<int>& qs) {
        int cnt = 0;
        for(int q : qs) {
            cnt += (q+x-1) / x;
        }
        return cnt <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1, hi = 100000;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(isPoss(mid, n, quantities)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
