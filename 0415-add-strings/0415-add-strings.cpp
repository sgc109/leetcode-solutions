class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string ans = "";
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;
        while(p1 >= 0 || p2 >= 0) {
            int digit1 = (p1 < 0 ? 0 : num1[p1] - '0');
            int digit2 = (p2 < 0 ? 0 : num2[p2] - '0');
            int sum = carry + digit1 + digit2;
            ans += '0' + sum % 10;
            carry = sum > 9;
            --p1;
            --p2;
        }
        if(carry) {
            ans += '1';
        }
        reverse(begin(ans), end(ans));
        return ans == "" ? "0" : ans;
    }
};