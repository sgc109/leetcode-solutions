class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> mapper;
        mapper['1'] = '1';
        mapper['6'] = '9';
        mapper['8'] = '8';
        mapper['9'] = '6';
        mapper['0'] = '0';
        string reversed = num;
        reverse(begin(reversed), end(reversed));
        for(int i = 0; i < num.size(); ++i) {
            if(reversed[i] != mapper[num[i]]) return false;
        }
        return true;
    }
};