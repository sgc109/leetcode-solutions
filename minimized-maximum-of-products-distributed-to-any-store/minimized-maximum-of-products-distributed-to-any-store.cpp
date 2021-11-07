class Solution {
    bool isPoss(int x, int n, vector<int> qs) {
        int pos = 0;
        for(int i = 0; i < n && pos < qs.size(); ++i) {
            if(qs[pos] <= x) ++pos;
            else qs[pos] -= x;
        }
        return pos == qs.size();
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 0, hi = 100000;
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