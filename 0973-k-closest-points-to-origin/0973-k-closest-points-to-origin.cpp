class Solution {
    struct Point {
        int x, y;
        bool operator<(const Point &rhs) const {
            return x * x + y * y < rhs.x * rhs.x + rhs.y * rhs.y;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<Point> pointsVec;
        for(auto point : points) {
            pointsVec.push_back(Point{point[0], point[1]});
        }
        sort(pointsVec.begin(), pointsVec.end());

        vector<vector<int>> ans;
        for(int i = 0; i < k; ++i) {
            auto point = pointsVec[i];
            ans.push_back({point.x, point.y});
        }

        return ans;
    }
};