class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int cntOpen = 0;
        for(char& c : s) {
            if(c == '(') {
                ++cntOpen;
            } else {
                if(!cntOpen) {
                    ++ans;
                } else {
                    --cntOpen;
                }
            }
        }
        return ans + cntOpen;
    }
};