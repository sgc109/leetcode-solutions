class Solution {
    string shiftToLeftMost(string& original) {
        string shifted = "";
        int diff = 'a' - original[0];
        for(char c : original) {
            shifted += ((c - 'a' + diff + 26) % 26) + 'a';
        }
        return shifted;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hashMap;

        for(string str : strings) {
            string key = shiftToLeftMost(str);
            hashMap[key].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(auto it : hashMap) {
            ans.push_back(it.second);
        }
        return ans;
    }
};