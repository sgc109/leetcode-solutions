class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cntOnesOnLeft = 0;
        int cntZerosOnRight = 0;
        for(auto c : s) {
            if(c == '0') {
                ++cntZerosOnRight;
            }
        }
        int ans = cntZerosOnRight;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '0') {
                --cntZerosOnRight;
            } else {
                ++cntOnesOnLeft;
            }
            ans = min(ans, cntOnesOnLeft + cntZerosOnRight);
        }
        return ans;
    }
};