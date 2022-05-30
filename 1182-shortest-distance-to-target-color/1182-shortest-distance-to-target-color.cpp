class Solution {
    const int INF = 987654321;
    int N;
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        N = colors.size();
        
        vector<vector<int>> poses = vector<vector<int>>(3, vector<int>());
        for(int i = 0; i < colors.size(); ++i) {
            int color = colors[i] - 1;
            poses[color].push_back(i);
        }
        
        vector<int> ans;
        
        for(vector<int>& q : queries) {
            int idx = q[0];
            int color = q[1] - 1;
            
            int targetIdx = lower_bound(begin(poses[color]), end(poses[color]), idx) - begin(poses[color]);
            int minD = INF;
            if(targetIdx < poses[color].size()) {
                minD = min(minD, poses[color][targetIdx] - idx);
            }
            if(targetIdx - 1 < poses[color].size()) {
                minD = min(minD, idx - poses[color][targetIdx - 1]);
            }
            ans.push_back(minD == INF ? -1 : minD);
        }
        
        return ans;
    }
};