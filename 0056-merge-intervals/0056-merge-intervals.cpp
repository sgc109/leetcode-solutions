class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) {
            return intervals;
        }
        sort(begin(intervals), end(intervals));
        vector<vector<int>> ret;
        
        int s = intervals[0][0];
        int e = intervals[0][1];
        for(auto p : intervals) {
            if(e < p[0]) {
                ret.push_back(vector<int>({s, e}));
                s = p[0];
                e = p[1];
            } else {
                e = max(e, p[1]);
            }
        }
        ret.push_back(vector<int>({s, e}));
        
        return ret;
    }
};