class Solution {
    const int INF = 16e8 + 1;
    
    unordered_set<int> memo;
    int calcIdx(int x, int y) {
        return x * 40001 + y;
    }
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INF;
        
        int N = points.size();
        for(int i = 0; i < N; ++i) {
            int x = points[i][0];
            int y = points[i][1];
            memo.insert(calcIdx(x, y));
        }
        for(int i = 0; i < N - 1; ++i) {
            for(int j = i + 1; j < N; ++j) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1 == x2 || y1 == y2) {
                    continue;
                }
                if(memo.count(calcIdx(x1, y2)) == 0 || memo.count(calcIdx(x2, y1)) == 0) {
                    continue;
                }
                int w = abs(points[i][0] - points[j][0]);
                int h = abs(points[i][1] - points[j][1]);
                ans = min(ans, w * h);
            }
        }
        
        return ans == INF ? 0 : ans;
    }
};