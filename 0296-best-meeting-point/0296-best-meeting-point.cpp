class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<pair<int,int>> homes;
        vector<int> rows;
        vector<int> cols;
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                if(grid[i][j]) {
                    homes.emplace_back(i, j);
                    rows.push_back(i);
                }
            }
        }
        for(int i = 0; i < C; ++i) {
            for(int j = 0; j < R; ++j) {
                if(grid[j][i]) {
                    cols.push_back(i);
                }
            }
        }
        int N = homes.size();
        int ans = 0;
        for(auto& p : homes) {
            ans += abs(p.first - rows[rows.size() / 2]) + abs(p.second - cols[cols.size() / 2]);
        }
        return ans;
    }
};