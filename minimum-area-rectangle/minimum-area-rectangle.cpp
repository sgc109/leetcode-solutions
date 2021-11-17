class Solution {
    unordered_map<int, unordered_set<int>> x2y;
public:
    int minAreaRect(vector<vector<int>>& points) {
        for(auto p : points) {
            x2y[p[0]].insert(p[1]);
        }
        int N = points.size();
        int ans = INT_MAX;
        for(int i = 0; i < N-1; ++i) {
            for(int j = i+1; j < N; ++j) {
                if(points[i][0] == points[j][0] ||
                  points[i][1] == points[j][1]) continue;
                if(x2y[points[i][0]].find(points[j][1]) == x2y[points[i][0]].end()) continue;
                if(x2y[points[j][0]].find(points[i][1]) == x2y[points[j][0]].end()) continue;
                int w = abs(points[i][0] - points[j][0]);
                int h = abs(points[i][1] - points[j][1]);
                ans = min(ans, w * h);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};