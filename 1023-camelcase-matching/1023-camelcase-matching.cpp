class Solution {
    bool isLowerAlpha(char c) {
        return 'a' <= c && c <= 'z';
    }

    bool match(string& cand, string& target) {
        int pos = 0;
        int last = 0;
        for(; last < target.size(); ++last) {
            char c = target[last];
            if(pos == cand.size()) {
                break;
            }
            if(cand[pos] == c) {
                ++pos;
            } else if(!isLowerAlpha(c)){
                return false;
            }
        }
        if(pos != cand.size()) {
            return false;
        }
        for(int i = last; i < target.size(); ++i) {
            if(!isLowerAlpha(target[i])) {
                return false;
            }
        }
        return true;
    }
public:

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;

        for(string& s : queries) {
            answer.push_back(match(pattern, s));
        }
        return answer;
    }
};