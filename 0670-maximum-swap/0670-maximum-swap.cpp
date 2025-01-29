class Solution {
public:
    int maximumSwap(int num) {
        if(num < 10) {
            return num;
        }

        int cntDigits = 0;
        int curNum = num;
        while(curNum) {
            curNum /= 10;
            cntDigits++;
        }

        int ans = num;
        for(int i = 0; i < cntDigits; ++i) {
            for(int j = i + 1; j < cntDigits; ++j) {
                int tmp = num;

                int digit1 = num / (int)pow(10, i) % 10;
                int digit2 = num / (int)pow(10, j) % 10;

                tmp -= digit1 * pow(10, i);
                tmp -= digit2 * pow(10, j);
                tmp += digit1 * pow(10, j);
                tmp += digit2 * pow(10, i);

                ans = max(ans, tmp);
            }
        }

        return ans;
    }
};