class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        
        int len = num.size();
        for(int i = 0; i < len; ++i) {
            while(k > 0 && ans.size() > 0 && ans.back() > num[i]) {
                ans.pop_back();
                --k;
            }
            ans += num[i];
        }
        
        while(k > 0) {
            ans.pop_back();
            --k;
        }
        
        reverse(begin(ans), end(ans));
        
        while(ans.size() > 0 && ans.back() == '0') {
            ans.pop_back();
        }
        
        if(ans.size() == 0) {
            ans += '0';
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};