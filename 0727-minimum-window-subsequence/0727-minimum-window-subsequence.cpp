/*
Took: 40m 26s
Time: O(len(s1) * len(s2))
Space: O(len(s1))
*/

class Solution {
    const int INF = 987654321;
    vector<vector<int>> closest;
public:
    string minWindow(string s1, string s2) {
        int A = s1.size();
        int B = s2.size();
        
        closest = vector<vector<int>>(A + 1, vector<int>(26, A));
        for(int i = A - 1; i >= 0; --i) {
            for(int j = 0; j < 26; ++j) {
                closest[i][j] = closest[i + 1][j];
            }
            closest[i][s1[i] - 'a'] = i;
        }
        string ans = "";
        int l = -1, r = -1;
        for(int i = 0; i < A; ++i) {
            int pos = i;
            int j;
            for(j = 0; j < B; ++j) {
                int cur = closest[pos][s2[j] - 'a'];
                if(cur == A) {
                    break;
                }
                pos = cur + 1;
            }
            if(j == B) {
                if(l == -1) {
                    l = i;
                    r = pos;
                } else {
                    if(r - l > pos - i) {
                        l = i;
                        r = pos;
                    }
                }
            }
        }

        if(l == -1) {
            return "";
        } else {
            return s1.substr(l, r - l);
        }
    }
};