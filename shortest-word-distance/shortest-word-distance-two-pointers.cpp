class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> poses1, poses2;
        for(int i = 0; i < wordsDict.size(); ++i) {
            string word = wordsDict[i];
            if(word == word1) {
                poses1.push_back(i);
            } else if(word == word2) {
                poses2.push_back(i);
            }
        }
        int ans = 30000;
        int p1 = 0, p2 = 0;
        while(p1 < poses1.size() && p2 < poses2.size()) {
            int idx1 = poses1[p1];
            int idx2 = poses2[p2];
            ans = min(ans, abs(idx1 - idx2));
            if(idx1 < idx2) {
                ++p1;
            } else {
                ++p2;
            }
        }
        return ans;
    }
};
