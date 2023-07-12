/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

struct Range {
    int s, e;
    bool operator<(const Range& rhs) const {
        return s < rhs.s;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Range> ranges;
        for(auto employee : schedule) {
            for(auto inter : employee) {
                ranges.push_back(Range{inter.start, inter.end});
            }
        }
        sort(begin(ranges), end(ranges));
        
        int last = -1;
        vector<Interval> ans;
        for(auto range : ranges) {
            if(last != -1 && last < range.s) {
                ans.push_back(Interval{last, range.s});
            }
            last = max(last, range.e);
        }
        
        return ans;
    }
};