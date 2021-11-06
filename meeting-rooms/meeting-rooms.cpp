class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int last = -1;
        for(auto interval : intervals) {
            int s = interval[0];
            int e = interval[1];
            if(s < last) return false;
            last = e;
        }
        return true;
    }
};