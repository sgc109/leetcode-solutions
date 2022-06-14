class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> stk;
        for(char c : s) {
            bool isTopCur = stk.size() > 0 && stk.back().first == c;
            if(isTopCur && stk.back().second + 1 == k) {
                stk.pop_back();
            } else {
                if(isTopCur) {
                    stk.back().second += 1;
                } else {
                    stk.push_back({c, 1});
                }
            }
        }
        string ans;
        for(auto p : stk) {
            ans += string(p.second, p.first);
        }
        return ans;
    }
};