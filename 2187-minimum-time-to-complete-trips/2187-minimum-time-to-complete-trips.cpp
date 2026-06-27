class Solution {
    bool check(vector<int>& time, int totalTrips, long long timeCap) {
        long long possibleTrips = 0;
        for(int t : time) {
            possibleTrips += timeCap / t;
        }
        return possibleTrips >= totalTrips;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = 0;
        long long hi = 1e14;
        while(lo < hi) {
            long long mid = (lo + hi) / 2;
            if(check(time, totalTrips, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};