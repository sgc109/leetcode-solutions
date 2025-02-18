class Solution {
    bool isDigits(string s) {
        if(s.size() == 0) {
            return false;
        }
        for(char& c : s) {
            if(!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    bool isExponent(string s) {
        if(s.size() == 0) {
            return false;
        }
        if(s[0] != 'e' && s[0] != 'E') {
            return false;
        }
        s = s.substr(1, s.size() - 1);
        return isIntegerNumber(s);
    }

    bool isDecimalNumber(string s) { // 0.8
        if(s.size() == 0) {
            return false;
        }
        if(s[0] == '+' || s[0] == '-') {
            s = s.substr(1, s.size() - 1);
        }
        if(s.size() == 0) {
            return false;
        }
        if(s.back() == '.') {
            s.pop_back();
            return isDigits(s);
        } else if(s[0] == '.') {
            s = s.substr(1, s.size() - 1);
            return isDigits(s);
        } else {
            int idxDot = -1; // 1
            for(int i = 0; i < s.size(); ++i) { // 0.8
                if(s[i] == '.') {
                    idxDot = i;
                    break;
                }
            }
            string left = s.substr(0, idxDot); // 0
            string right = s.substr(idxDot + 1, s.size() - idxDot - 1);
            return isDigits(left) && isDigits(right);
        }
    }

    bool isIntegerNumber(string s) {
        if(s.size() == 0) {
            return false;
        }
        if(s[0] == '+' || s[0] == '-') {
            s = s.substr(1, s.size() - 1);
        }
        return isDigits(s);
    }
public:
    bool isNumber(string s) { // "0.8"
        int idxOfE = -1;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'e' || s[i] == 'E') {
                idxOfE = i;
                break;
            }
        }
        if(idxOfE == -1) {
            return isIntegerNumber(s) || isDecimalNumber(s);
        } else {
            string left = s.substr(0, idxOfE);
            string right = s.substr(idxOfE, s.size() - idxOfE);
            return (isIntegerNumber(left) || isDecimalNumber(left)) && isExponent(right);
        }
    }
};