class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result = "";

        vector<int> openingIndexes;
        vector<bool> shouldRemove(s.size(), false);
        
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                openingIndexes.push_back(i);
            } else if(s[i] == ')') {
                if(openingIndexes.size() == 0) {
                    shouldRemove[i] = true;
                } else {
                    openingIndexes.pop_back();
                }
            }
        }

        for(auto idx : openingIndexes) {
            shouldRemove[idx] = true;
        }

        for(int i = 0; i < s.size(); ++i) {
            if(!shouldRemove[i]) {
                result += s[i];
            }
        }
        
        return result;
    }
};