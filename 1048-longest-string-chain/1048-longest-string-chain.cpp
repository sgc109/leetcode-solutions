class Solution {
    vector<vector<int>> buckets = vector<vector<int>>(17, vector<int>());
    unordered_map<string,int> wordIdx;
public:
    int longestStrChain(vector<string>& words) {
        int N = words.size();
        for(int i = 0; i < N; ++i) {
            wordIdx[words[i]] = i;
            buckets[words[i].size()].push_back(i);
        }
        vector<int> sorted;
        for(int i = 1; i <= 16; ++i) {
            for(int idx : buckets[i]) {
                sorted.push_back(idx);
            }
        }
        
        int ans = 1;
        vector<int> maxLen(N, 1);
        
        for(int idx : sorted) {
            string word = words[idx];
            for(int i = 0; i < word.size(); ++i) {
                string newWord = "";
                if(i > 0) {
                    newWord += word.substr(0, i);
                }
                if(i < word.size() - 1) {
                    newWord += word.substr(i+1, word.size());
                }
                if(wordIdx.count(newWord) > 0) {
                    int preIdx = wordIdx[newWord];
                    maxLen[idx] = max(maxLen[idx], maxLen[preIdx] + 1);
                    ans = max(ans, maxLen[idx]);
                }
            }
        }
        return ans;
    }
};