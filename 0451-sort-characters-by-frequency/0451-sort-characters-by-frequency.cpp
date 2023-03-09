class Solution {
public:
    struct Ottur {
        int frq;
        char c;

        bool operator<(const Ottur& rhs) const {
            if(frq != rhs.frq) {
                return frq > rhs.frq;
            }
            return c < rhs.c;
        }
    };

    string frequencySort(string s) {
        unordered_map<char, int> counter;
        for(char c : s) {
            counter[c]++;
        }
        vector<Ottur> otturs;
        for(auto p : counter) {
            otturs.push_back(Ottur{p.second, p.first});
        }    
        sort(begin(otturs), end(otturs));
        string ans = "";
        for(auto p : otturs) {
            while(p.frq--) {
                ans += p.c;
            }
        }
        return ans;
    }
};