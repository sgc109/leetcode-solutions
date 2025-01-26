class Solution {
    bool canEatAll(vector<int>& piles, int speed, int limitHour) {
        int hours = 0;
        for(int pile : piles) {
            hours += (int)(pile / speed) + (pile % speed != 0);
        }
        return hours <= limitHour;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = -1;
        for(int pile : piles) {
            hi = max(hi, pile);
        }
        
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(canEatAll(piles, mid, h)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
