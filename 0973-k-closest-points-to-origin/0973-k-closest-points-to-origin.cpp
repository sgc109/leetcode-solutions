class Solution {
    typedef vector<int> Point;
    function<bool(Point&, Point&)> cmp = [](Point& a, Point& b) {
        return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    };
        function<bool(Point&, Point&)> cmp2 = [](Point& a, Point& b) {
        return a[0] * a[0] + a[1] * a[1] <= b[0] * b[0] + b[1] * b[1];
    };
    void quickSelect(int l, int r, int k, vector<Point>& points, vector<Point>& ans) { // 0, 1, 0, [[-2,2],[1,3]], [[-2,2]]
        int randIdx = rand() % (r - l + 1) + l;
        swap(points[randIdx], points[r]);
        int p = l;
        for(int i = l; i < r; ++i) {
            int sameToTheRight = rand() % 2;
            if((sameToTheRight && cmp(points[i], points[r]) ||
               (!sameToTheRight && cmp2(points[i], points[r]))
            )) {
                swap(points[i], points[p]);
                ++p;
            }
        }
        swap(points[p], points[r]);
        if(p == k) {
            for(int i = l; i <= p; ++i) {
                ans.push_back(points[i]);
            }
        } else if(p < k) {
            for(int i = l; i <= p; ++i) {
                ans.push_back(points[i]);
            }
            quickSelect(p + 1, r, k, points, ans);
        } else {
            quickSelect(l, p - 1, k, points, ans);
        }
    }
public:
// points = [[1,3],[-2,2]], k = 1
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        --k;
        vector<Point> ans;
        quickSelect(0, points.size() - 1, k, points, ans);
        return ans;
    }
};