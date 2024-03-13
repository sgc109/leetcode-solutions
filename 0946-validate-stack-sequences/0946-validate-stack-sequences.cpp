class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        unordered_set<int> seen;
        vector<int> stk;

        int p1 = 0, p2 = 0;
        while(p1 < pushed.size()) {
            if(stk.size() == 0 || stk.back() != popped[p2]) {
                if(seen.count(popped[p2]) > 0) {
                    return false;
                }
                seen.insert(pushed[p1]);
                stk.push_back(pushed[p1]);
                ++p1;
            } else {
                stk.pop_back();
                ++p2;
            }
        }

        while(p2 < popped.size()) {
            if(stk.back() != popped[p2]) {
                return false;
            }
            stk.pop_back();
            ++p2;
        }
        
        return p2 == popped.size();
    }
};