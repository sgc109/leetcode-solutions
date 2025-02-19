class Solution {
    bool isDigits(string s) {
        if(s.empty()) {
            return false;
        }
        return all_of(s.begin(), s.end(), ::isdigit);
    }

    bool isExponent(string s) {
        if(s.empty()) {
            return false;
        }
        if(s[0] != 'e' && s[0] != 'E') {
            return false;
        }
        s = s.substr(1, s.size() - 1);
        return isIntegerNumber(s);
    }

    bool isDecimalNumber(string s) { // 0.8
        if(s.empty()) {
            return false;
        }
        if(s[0] == '+' || s[0] == '-') {
            s = s.substr(1, s.size() - 1);
        }
        if(s.empty()) {
            return false;
        }
        if(s.back() == '.') {
            s.pop_back();
            return isDigits(s);
        } else if(s[0] == '.') {
            s = s.substr(1, s.size() - 1);
            return isDigits(s);
        } else {
            int idxDot = s.find('.');
            string left = s.substr(0, idxDot); // 0
            string right = s.substr(idxDot + 1, s.size() - idxDot - 1);
            return isDigits(left) && isDigits(right);
        }
    }

    bool isIntegerNumber(string s) {
        if(s.empty()) {
            return false;
        }
        if(s[0] == '+' || s[0] == '-') {
            s = s.substr(1, s.size() - 1);
        }
        return isDigits(s);
    }
public:
    bool isNumber(string s) { // "0.8"
        int idxOfE = max((int)s.find('e'), (int)s.find('E'));
        if(idxOfE == -1) {
            return isIntegerNumber(s) || isDecimalNumber(s);
        } else {
            string left = s.substr(0, idxOfE);
            string right = s.substr(idxOfE, s.size() - idxOfE);
            return (isIntegerNumber(left) || isDecimalNumber(left)) && isExponent(right);
        }
    }
};