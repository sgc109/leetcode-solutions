class Solution {
    struct Point {
        int x;
        int y;
        bool operator<(const Point& rhs) const {
            return x * x + y * y < rhs.x * rhs.x + rhs.y * rhs.y;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point> pq;
        for(int i = 0; i < points.size(); ++i) {
            pq.push(Point{points[i][0], points[i][1]});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ans.push_back({top.x, top.y});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};