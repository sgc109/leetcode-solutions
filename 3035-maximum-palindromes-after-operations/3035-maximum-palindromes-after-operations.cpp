class Solution {
    bool use(vector<int>& odds, vector<int>& evens, int size) {
        if(size % 2 == 1) {
            if(odds.size() > 0) {
                int last = odds.back();
                odds.pop_back();
                --last;
                --size;
                if(last > 0) {
                    evens.push_back(last);
                }
            } else {
                if(evens.size() == 0) {
                    return false;
                }
                int last = evens.back();
                evens.pop_back();
                --last;
                --size;
                if(last > 0) {
                    odds.push_back(last);
                }
            }
        }
        if(size == 0) {
            return true;
        }
        while(evens.size() > 0) {
            int last = evens.back();
            evens.pop_back();
            if(size > last) {
                size -= last;
            } else {
                last -= size;
                if(last > 0) {
                    evens.push_back(last);   
                }
                return true;
            }
        }
        for(int i = 0; i < odds.size(); ++i) {
            if(odds[i] > size) {
                odds[i] -= size;
                return true;
            } else {
                size -= (odds[i] - 1);
                odds[i] = 1;
            }
        }
        return false;
    }
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> sizes;
        unordered_map<char, int> counter;
        for(auto word : words) {
            sizes.push_back(word.size());
            for(auto ch : word) {
                counter[ch]++;
            }
        }
        vector<int> odds, evens;
        for(auto it : counter) {
            if(it.second % 2 == 0) {
                evens.push_back(it.second);
            } else {
                odds.push_back(it.second);
            }
        }
        sort(begin(sizes), end(sizes));
        int ans = 0;
        for(int size : sizes) {
            if(!use(odds, evens, size)) {
                break;
            }
            ++ans;
        }
        return ans;
    }
};