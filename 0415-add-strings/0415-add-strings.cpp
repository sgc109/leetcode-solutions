class Solution {
public:
    string addStrings(string num1, string num2) {
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;
        int carry = 0;
        string ans = "";
        while(p1 >= 0 || p2 >= 0) {
            int n1 = p1 >= 0 ? num1[p1] - '0' : 0;
            int n2 = p2 >= 0 ? num2[p2] - '0' : 0;
            int sum = n1 + n2 + carry;
            ans += '0' + (sum % 10);
            carry = sum >= 10 ? 1 : 0;
            --p1;
            --p2;
        }
        if(carry) {
            ans += '1';
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};