/*
(y1 - y2) / (x1 - x2)
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int N = points.size();
        int ans = 1;
        for(int i = 0; i < N; ++i) {
            unordered_map<double, int> angleToCnt;
            int cntWithSameX = 0;
            for(int j = 0; j < N; ++j) {
                if(i == j) {
                    continue;
                }
                if(points[i][0] == points[j][0]) {
                    cntWithSameX++;
                    ans = max(ans, cntWithSameX + 1);
                } else {
                    double angle = (double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                    angleToCnt[angle]++;
                    ans = max(ans, angleToCnt[angle] + 1);
                }
            }
        }
        return ans;
    }
};