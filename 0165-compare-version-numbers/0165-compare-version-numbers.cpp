/*

version1 = 00000

version = 1.
version = .1
version = .
version = 1..1

*/

class Solution {
    vector<int> convert(string verStr) {
        verStr += '.';
        vector<int> ret;
        int prv = -1;
        for(int i = 0; i < verStr.size(); ++i) {
            if(verStr[i] == '.') {
                string substr = verStr.substr(prv + 1, i);
                int revision = stoi(substr);
                ret.push_back(revision);
                prv = i;
            }
        }
        
        return ret;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1 = convert(version1);
        vector<int> vec2 = convert(version2);
        auto& targetToAdd = vec1.size() < vec2.size() ? vec1 : vec2;

        while(vec1.size() != vec2.size()) {
            targetToAdd.push_back(0);
        }

        for(int i = 0; i < vec1.size(); ++i) {
            if(vec1[i] < vec2[i]) {
                return -1;
            } else if(vec1[i] > vec2[i]) {
                return 1;
            }
        }

        return 0;
    }
};