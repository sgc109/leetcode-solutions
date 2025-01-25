class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(size(s) < size(p)) {
            return vector<int>();
        }

        vector<int> countsOfS(26, 0);
        vector<int> countsOfP(26, 0);
        int cntMatched = 0;
        int uniqueAlphaOfP = 0;
        
        // 1. initialize countsOfP, uniqueAlphaOfP
        for(auto c : p) {
            countsOfP[c - 'a']++;
        }
        
        // 2. initialize countsOfS, cntMatched with first window
        for(int i = 0; i < size(p); ++i) {
            countsOfS[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; ++i) {
            if(countsOfS[i] == countsOfP[i]) {
                ++cntMatched;
            }
        }

        vector<int> ans;

        if(cntMatched == 26) {
            ans.push_back(0);
        }

        for(int i = size(p); i < size(s); ++i) {
            int posNew = s[i] - 'a';
            countsOfS[posNew]++;
            if(countsOfS[posNew] == countsOfP[posNew]) {
                ++cntMatched;
            } else if(countsOfS[posNew] == countsOfP[posNew] + 1) {
                --cntMatched;
            }
            int posOld = s[i - size(p)] - 'a';
            countsOfS[posOld]--;
            if(countsOfS[posOld] == countsOfP[posOld]) {
                ++cntMatched;
            } else if(countsOfS[posOld] == countsOfP[posOld] - 1) {
                --cntMatched;
            }
            if(cntMatched == 26) {
                ans.push_back(i - size(p) + 1);
            }
        }

        return ans;
    }
};