class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> queue;
        unordered_map<string, int> dists;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        dists[beginWord] = 0;
        queue.push(beginWord);
        while(!queue.empty()) {
            string cur = queue.front();
            queue.pop();
            int curDist = dists[cur];
            if(cur == endWord) {
                return curDist + 1;
            }
            for(int i = 0; i < cur.size(); ++i) {
                for(int j = 0; j < 26; ++j) {
                    string next = "";
                    for(int k = 0; k < i; ++k) {
                        next += cur[k];
                    }
                    next += 'a' + j;
                    for(int k = i+1; k < cur.size(); ++k) {
                        next += cur[k];
                    }
                    if(wordSet.count(next) == 0 || dists.count(next) > 0) {
                        continue;
                    }
                    dists[next] = curDist + 1;
                    queue.push(next);
                }
            }
        }
        
        return 0;
    }
};