class Solution {
    struct Pos{
      int r, c;
        bool operator==(const Pos& rhs) const {
            return r == rhs.r && c == rhs.c;
        }
    };
    Pos calcPos(char alpha) {
        int idx = alpha - 'a';
        return Pos{idx / 5, idx % 5};
    }
public:
    string alphabetBoardPath(string target) {
        string ans = "";
        
        Pos curPos = calcPos('a');
        for(char next : target) {
            auto nextPos = calcPos(next);
            if(curPos == nextPos) {
                ans += '!';
                continue;
            }
            
            int rDiff = nextPos.r - curPos.r;
            int cDiff = nextPos.c - curPos.c;
            
            string rStr = "";
            for(int i = 0; i < abs(rDiff); ++i) {
                rStr += (rDiff > 0 ? 'D' : 'U');
            }
            
            string cStr = "";
            for(int i = 0; i < abs(cDiff); ++i) {
                cStr += (cDiff > 0 ? 'R' : 'L');
            }
            
            if(next == 'z') {
                ans += cStr + rStr;
            } else {
                ans += rStr + cStr;
            }
            ans += '!';
            curPos = nextPos;
        }
        return ans;
    }
};