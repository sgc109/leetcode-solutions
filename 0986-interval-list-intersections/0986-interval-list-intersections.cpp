/*
[[1,2]]
[[]]
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int p1 = 0;
        int p2 = 0;
        vector<vector<int>> ans;
        while(p1 < firstList.size() && p2 < secondList.size()) {
            int start1 = firstList[p1][0];
            int end1 = firstList[p1][1];
            int start2 = secondList[p2][0];
            int end2 = secondList[p2][1];

            if(end1 <= end2) {
                if(start2 <= end1) {
                    ans.push_back({max(start1, start2), end1});
                }
                ++p1;
            } else {
                if(start1 <= end2) {
                    ans.push_back({max(start1, start2), end2});
                }
                ++p2;
            }
        }
        return ans;
    }
};