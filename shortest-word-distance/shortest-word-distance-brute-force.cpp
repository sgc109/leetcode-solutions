class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int ans = 30000;
        int p1 = -1, p2 = -1;
        for(int i = 0; i < wordsDict.size(); ++i) {
            string word = wordsDict[i];
            if(word == word1) {
                p1 = i;
            } else if(word == word2) {
                p2 = i;
            }
            if(p1 != -1 && p2 != -1) {
                ans = min(ans, abs(p1 - p2));
            }
        }
        
        return ans;
    }
};
