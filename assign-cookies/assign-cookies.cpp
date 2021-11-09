class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int p1 = 0, p2 = 0;
        int ans = 0;
        while(p1 < g.size() && p2 < s.size()) {
            if(g[p1] <= s[p2]) {
                ++ans;
                ++p1;
                ++p2;
            } else {
                ++p2;
            }
        }
        return ans;
    }
};