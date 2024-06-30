class Solution {
    void solve(int idx, vector<pair<int,int>>& numCnts, int curTarget, vector<int>& comb, vector<vector<int>>& ans) {
        if(idx == numCnts.size()) {
            if(curTarget == 0) {
                vector<int> toPush(comb.begin(), comb.end());
                ans.push_back(toPush);
            }
            return;
        }
        for(int i = 0; i <= numCnts[idx].second; ++i) {
            int toAdd = i * numCnts[idx].first;
            if(toAdd > curTarget) {
                break;
            }
            for(int j = 0; j < i; ++j) {
                comb.push_back(numCnts[idx].first);
            }
            solve(idx + 1, numCnts, curTarget - toAdd, comb, ans);
            for(int j = 0; j < i; ++j) {
                comb.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        unordered_map<int,int> numCnts;
        
        for(int num : candidates) {
            numCnts[num]++;
        }

        vector<pair<int,int>> numCntPairs;
        for(auto it : numCnts) {
            numCntPairs.emplace_back(it.first, it.second);
        }
        
        vector<int> comb;
        solve(0, numCntPairs, target, comb, ans);

        return ans;
    }
};