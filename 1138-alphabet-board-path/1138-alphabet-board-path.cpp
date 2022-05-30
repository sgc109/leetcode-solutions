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
            
            string rStr = string(abs(rDiff), rDiff > 0 ? 'D' : 'U');
            string cStr = string(abs(cDiff), cDiff > 0 ? 'R' : 'L');
            
            if(next == 'z') {
                ans += cStr;
                ans += rStr;
            } else {
                ans += rStr;
                ans += cStr;
            }
            ans += '!';
            curPos = nextPos;
        }
        return ans;
    }
};