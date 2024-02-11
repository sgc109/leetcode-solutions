/*
Time: O(N * L^2)
Space: O(N * L)
*/

class Solution {
    unordered_map<string, vector<string>> prefixStrs;
    void solve(vector<string>& strs, vector<vector<string>>& ans) {
        if(strs.size() > 0 && strs.size() == strs[0].size()) {
            ans.push_back(strs);
            return;
        }
        string nextPrefix = "";
        for(int i = 0; i < size(strs); ++i) {
            nextPrefix += strs[i][size(strs)];
        }
        for(auto str : prefixStrs[nextPrefix]) {
            strs.push_back(str);
            int pos = strs.size();
            solve(strs, ans);
            strs.pop_back();
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        for(auto str : words) {
            for(int i = 0; i < str.size(); ++i) {
                auto substr = str.substr(0, i);
                prefixStrs[substr].push_back(str);
            }
        }
        vector<string> strs;
        vector<vector<string>> ans;
        solve(strs, ans);

        return ans;
    }
};