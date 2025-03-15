class Solution {
    struct Comparator {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq; // [(3,3,18),(-2,4,20)]
        for(auto& point : points) {
            pq.push(point);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans; // [(-2,2)]
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};