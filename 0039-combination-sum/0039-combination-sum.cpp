class Solution {
    vector<int> cand;
    vector<vector<int>> ans;
    
    void solve(int curNum, int pos, vector<int>& curNums) {
        if(curNum == 0) {
            vector<int> tmp(curNums);
            ans.push_back(tmp);
            return;
        }
        if(pos == -1) {
            return;
        }
        solve(curNum, pos - 1, curNums); // not choosing cur num

        vector<int> clone(curNums);
        for(int i = 1; cand[pos] * i <= curNum; ++i) {
            clone.push_back(cand[pos]);
            solve(curNum - cand[pos] * i, pos - 1, clone);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {        
        int N = candidates.size();
        cand = candidates;
        
        vector<int> curNums;
        solve(target, N - 1, curNums);

        return ans;
    }
};