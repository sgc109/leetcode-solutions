class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));
        int pos = 0;
        int carry = 0;
        string concat = "";
        while(pos < num1.size() && pos < num2.size()) {
            int n1 = num1[pos] - '0';
            int n2 = num2[pos] - '0';
            int res = n1 + n2 + carry;
            concat += '0' + (res % 10);
            carry = res > 9 ? 1 : 0;
            ++pos;
        }
        while(pos < num1.size()) {
            int n1 = num1[pos] - '0';
            int res = n1 + carry;
            concat += '0' + (res % 10);
            carry = res > 9 ? 1 : 0;
            ++pos;
        }

        while(pos < num2.size()) {
            int n2 = num2[pos] - '0';
            int res = n2 + carry;
            concat += '0' + (res % 10);
            carry = res > 9 ? 1 : 0;
            ++pos;
        }

        if(carry) {
            concat += '1';
        }

        reverse(begin(concat), end(concat));
        
        return concat;
    }
};