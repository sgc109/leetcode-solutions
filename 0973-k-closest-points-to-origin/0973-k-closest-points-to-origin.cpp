class Solution {
    struct Point {
        int x;
        int y;
        bool operator<(const Point& rhs) const {
            return x * x + y * y < rhs.x * rhs.x + rhs.y * rhs.y;
        }
    };
public:
// points = [], k = 
//                          ^
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point> pq; // [(3,3,18),(-2,4,20)]
        for(auto& point : points) {
            pq.push(Point{point[0], point[1]});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans; // [(-2,2)]
        while(!pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.push_back({x, y});
        }
        return ans;
    }
};