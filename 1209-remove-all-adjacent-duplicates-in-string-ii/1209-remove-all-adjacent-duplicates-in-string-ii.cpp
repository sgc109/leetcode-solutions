class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> stk;
        for(char c : s) {
            bool isTopCur = stk.size() > 0 && stk.back().first == c;
            if(isTopCur && stk.back().second + 1 == k) {
                for(int i = 0; i < k - 1; ++i) {
                    stk.pop_back();
                }
            } else {
                int cnt = 1;
                if(isTopCur) {
                    cnt = stk.back().second + 1;
                }
                stk.push_back({c, cnt});
            }
        }
        string ans;
        for(auto p : stk) {
            ans += p.first;
        }
        return ans;
    }
};