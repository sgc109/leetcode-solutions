typedef long long ll;

class Solution {
    double pow(double x, ll n) {
        if(n == 0) {
            return 1.0;
        }
        if(n < 0) {
            return pow(1.0 / x, -n);
        }
        if(n % 2 == 1) {
            return x * pow(x, n - 1);
        }
        double half = pow(x, n / 2);
        return half * half;
    }
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
};