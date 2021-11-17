class Solution {
    const int INF = INT_MAX;
    struct Point {
        int x;
        int y;
    };
    
    map<int, vector<Point>> groupedByX;
    map<int, vector<Point>> groupedByY;
    unordered_set<int> pts;
    Point restPoint(Point& a, Point& b, Point& c) {
        return Point{a.x ^ b.x ^ c.x, a.y ^ b.y ^ c.y};
    }
public:
    int minAreaRect(vector<vector<int>>& points) {
        for(auto p : points) {
            int xx = p[0];
            int yy = p[1];
            if(groupedByX.find(xx) == groupedByX.end()) {
                groupedByX[xx] = vector<Point>();
            }
            if(groupedByY.find(yy) == groupedByY.end()) {
                groupedByY[yy] = vector<Point>();
            }
            groupedByX[xx].push_back(Point{xx,yy});
            groupedByY[yy].push_back(Point{xx,yy});
            pts.insert(xx*(40001) + yy);
        }
        int ans = INF;
        for(auto g : groupedByX) {
            auto group = g.second;
            for(int i = 0; i < group.size() - 1; ++i) {
                for(int j = i+1; j < group.size(); ++j) {
                    int h = abs(group[i].y - group[j].y);
                    for(auto p : groupedByY[group[i].y]) {
                        if(p.x == group[i].x && p.y == group[i].y) continue;
                        int w = max(abs(p.x - group[i].x), abs(p.x - group[j].x));
                        Point rest = restPoint(group[i], group[j], p);
                        if(pts.find(rest.x * 40001 + rest.y) != pts.end()) {
                            ans = min(ans, w * h);
                        }
                    }
                }
            }
        }
        return ans == INF ? 0 : ans;
    }
};