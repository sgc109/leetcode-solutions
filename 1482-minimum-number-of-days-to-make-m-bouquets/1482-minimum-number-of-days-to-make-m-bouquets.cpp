class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = 1, hi = 1e9 + 1;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            int made = 0;
            int conseq = 0;
            for(int day : bloomDay) {
                if(day > mid) {
                    conseq = 0;
                    continue;
                }
                conseq++;
                if(conseq == k) {
                    made++;
                    conseq = 0;
                }
                if(made == m) {
                    break;
                }
            }
            if(made == m) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if(lo == 1e9 + 1) {
            return -1;
        }
        return lo;
    }
};