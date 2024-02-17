class Solution {
public:
    int getSum(int a, int b) {
        int pos = 1;
        int carry = 0;
        int ans = 0;
        while(pos != 0) {
            int aBit = a & pos;
            int bBit = b & pos;
            if(aBit & bBit) {
                if(carry) {
                    ans |= pos;
                }
                carry = 1;
            } else if(aBit | bBit) {
                if(!carry) {
                    ans |= pos;
                    carry = 0;
                }
            } else {
                if(carry) {
                    ans |= pos;
                    carry = 0;
                }
            }
            pos <<= 1;
        }
        return ans;
    }
};