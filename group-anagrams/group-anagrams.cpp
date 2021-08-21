class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        for(auto str : strs) {
            string sorted = str;
            sort(begin(sorted), end(sorted));
            if(dict.count(sorted) == 0) {
                dict[sorted] = vector<string>();
            }
            dict[sorted].push_back(str);
        }
        vector<vector<string>> ret;
        for(auto& kv : dict) {
            ret.push_back(kv.second);
        }
        return ret;
    }
};
