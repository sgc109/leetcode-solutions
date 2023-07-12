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

class Solution {
    vector<pair<int,int>> mergeAll(vector<pair<int,int>> intervals) {
        vector<pair<int,int>> merged;

        for(auto inter : intervals) {
            if(merged.size() == 0 || merged.back().second < inter.first) {
                merged.push_back(inter);
            } else {
                merged.back() = {merged.back().first, max(merged.back().second, inter.second)};
            }
        }

        return merged;
    }
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<pair<int,int>> intervals;
        
        for(auto employee : schedule) {
            for(auto range : employee) {
                intervals.push_back({range.start, range.end});
            }
        }

        sort(begin(intervals), end(intervals));

        auto merged = mergeAll(intervals);

        vector<Interval> ans;
        for(int i = 0; i < merged.size() - 1; ++i) {
            ans.push_back(Interval(merged[i].second, merged[i+1].first));
        }

        return ans;
    }
};