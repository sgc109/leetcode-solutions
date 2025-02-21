/*

1 <= len(encoded1), len(encoded2) <= 10^5

1 <= vali <= 10^4
1 <= freqi <= 10^4

*/

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> ans;
        int p1 = 0, p2 = 0;
        while(p1 < encoded1.size() && p2 < encoded2.size()) {
            int production = encoded1[p1][0] * encoded2[p2][0];
            int minFreq = min(encoded1[p1][1], encoded2[p2][1]);
            if(ans.size() == 0 || ans.back()[0] != production) {
                ans.push_back({production, minFreq});
            } else {
                ans.back()[1] += minFreq;
            }
            encoded1[p1][1] -= minFreq;
            encoded2[p2][1] -= minFreq;
            if(encoded1[p1][1] == 0) {
                ++p1;
            }
            if(encoded2[p2][1] == 0) {
                ++p2;
            }
        }

        return ans;
    }
};