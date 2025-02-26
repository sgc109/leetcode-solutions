class Solution {
    bool isDigits(string& s) { // 123.456
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

    bool isDecimalNumber(string& s) { // -123.456
        if(s.empty()) {
            return false;
        }
        if(s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
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

    bool isIntegerNumber(string& s) { // -123.456
        if(s.empty()) {
            return false;
        }
        if(s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
        }
        if(s.empty()) {
            return false;
        }
        return isDigits(s); // 123.456
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
public: //                       012345678901
    bool isNumber(string s) { // -123.456e789
        int posE = max((int)s.find('e'), (int)s.find('E'));

        if(posE == -1) {
            return isIntegerNumber(s) || isDecimalNumber(s);
        }
        
        string integerOrDecimal = s.substr(0, posE); // -123.456
        string exponent = s.substr(posE); // e789
        return (isIntegerNumber(integerOrDecimal) || isDecimalNumber(integerOrDecimal)) && isExponent(exponent);
    }
};
