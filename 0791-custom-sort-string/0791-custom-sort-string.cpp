class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> counter;
        for(char c : s) {
            counter[c]++;
        }
        string ans = "";
        for(char c : order) {
            while(counter[c]--) {
                ans += c;
            }
            counter.erase(c);
        }
        for(auto it : counter) {
            while(it.second--) {
                ans += it.first;
            }
        }
        return ans;
    }
};