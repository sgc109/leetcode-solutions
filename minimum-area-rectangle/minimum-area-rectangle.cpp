// TC: O(N^2)
// SC: O(N)
// 일직선 상에 놓여 있지 않은 두 점이 정해지면 직사각형을 이루기 위한 나머지 두 점은 자동으로 정해지며, 전처리를 통해 O(1)로 나머지 두 점이 존재하는지 체크할 수 있다는 점을 이용
// 일직선 상에 놓여 있지 않은 모든 두 점의 쌍에 대해 O(1)로 계산을 하므로 O(N^2)

class Solution {
    unordered_set<int> coords;
public:
    int minAreaRect(vector<vector<int>>& points) {
        for(auto p : points) {
            coords.insert(p[0] * 40001 + p[1]);
        }
        int N = points.size();
        int ans = INT_MAX;
        for(int i = 0; i < N-1; ++i) {
            for(int j = i+1; j < N; ++j) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1 == x2 || y1 == y2) continue;
                if(coords.find(x1 * 40001 + y2) == coords.end()) continue;
                if(coords.find(x2 * 40001 + y1) == coords.end()) continue;
                int w = abs(x1 - x2);
                int h = abs(y1 - y2);
                ans = min(ans, w * h);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
