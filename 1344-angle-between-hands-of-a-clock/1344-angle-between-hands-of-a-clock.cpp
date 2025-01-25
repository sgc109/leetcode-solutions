class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourToMinute = (hour % 12) * 5.0 + (minutes / 60.0) * 5.0;
        return abs(hourToMinute - minutes) * 6.0;
    }
};