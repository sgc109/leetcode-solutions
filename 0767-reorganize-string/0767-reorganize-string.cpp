class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        vector<int> counter(26, 0);
        for(char c : s) {
            counter[c - 'a']++;
        }
        for(int i = 0; i < 26; ++i) {
            if(counter[i]) {
                pq.push({counter[i], 'a' + i});
            }
        }
        string ans = "";
        while(pq.size() > 0) {
            auto top = pq.top();
            char ch = top.second;
            int freq = top.first;
            pq.pop();
            if(ans == "" || ans.back() != ch) {
                ans += ch;
                if(freq > 1) {
                    pq.push({freq - 1, ch});
                }
            } else if(pq.size() == 0) {
                return "";
            } else {
                auto subTop = pq.top();
                pq.pop();
                ans += subTop.second;
                if(subTop.first > 1) {
                    pq.push({subTop.first - 1, subTop.second});
                }
                pq.push(top);
            }
        }

        return ans;
    }
};


/*

aaaaabbcc

a b a c a b a c a

*/