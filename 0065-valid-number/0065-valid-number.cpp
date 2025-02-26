class Solution {
    bool isDigits(string& s) {
        if(s.empty()) {
            return false;
        }
        for(char c : s) {
            if(!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    bool isDecimalNumber(string& s) {
        if(s.empty()) {
            return false;
        }
        int posDot = (int)s.find('.');
        if(posDot == -1) {
            return false;
        }
        string leftPart = s.substr(0, posDot);
        if(posDot > 0 && !isDigits(leftPart)) {
            return false;
        }
        string rightPart = s.substr(posDot + 1);
        if(posDot < s.size() - 1 && !isDigits(rightPart)) {
            return false;
        }
        return s.size() > 1;
    }

    bool isIntegerNumber(string& s) {
        if(s.empty()) {
            return false;
        }
        if(s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
        }
        return isDigits(s);
    }

    bool isExponent(string& s) {
        if(s.empty()) {
            return false;
        }
        if(s[0] != 'e' && s[0] != 'E') {
            return false;
        }
        string integerNumberMaybe = s.substr(1);
        return isIntegerNumber(integerNumberMaybe);
    }
public:
    bool isNumber(string s) {
        int posE = max((int)s.find('e'), (int)s.find('E'));

        if(posE == -1) {
            return isIntegerNumber(s) || isDecimalNumber(s);
        }
        
        string integerOrDecimal = s.substr(0, posE);
        string exponent = s.substr(posE);
        return (isIntegerNumber(integerOrDecimal) || isDecimalNumber(integerOrDecimal)) && isExponent(exponent);
    }
};