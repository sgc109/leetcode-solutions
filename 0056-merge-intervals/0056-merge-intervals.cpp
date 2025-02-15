class Solution {
    int starts[10003]; // [0, 1, 0, 0, 0, 0]
    int ends[10003]; // [0, -1, 0, 0, 0, 0]
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { // [[1,1]]
        int minNum = 10003; // 1
        int maxNum = -1; // 1
        for(auto inter : intervals) {
            starts[inter[0]]++;
            ends[inter[1]]--;
            minNum = min(minNum, inter[0]);
            maxNum = max(maxNum, inter[1]);
        }
        
        // starts = [0, 1, 0, 0, 0, 0]
        // ends = [0, -1, 0, 0, 0, 0]
        vector<vector<int>> ans; // [[1,1]]
        int acc = 0; // 0
        int start; // 1
        for(int i = minNum; i <= maxNum; ++i) { // i = 1
            if(starts[i] > 0 && acc == 0) {
                start = i;
            }
            acc += starts[i];

            if(ends[i] < 0 && ends[i] + acc == 0) {
                ans.push_back({start, i});
            }
            acc += ends[i];
        }
        return ans;
    }
};