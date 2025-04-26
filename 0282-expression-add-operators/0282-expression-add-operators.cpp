class Solution {
    typedef long long ll;
    string str;
    string candidate = "";
    int target;
    vector<string> ans;
    void find(int idx, ll acc, ll tmp, ll num, char prevOp) {
        if(str.size() == idx) {
            if(prevOp == '*') {
                tmp *= num;
            } else if(prevOp == '+') {
                acc += tmp;
                tmp = num;
            } else {
                acc += tmp;
                tmp = -num;
            }
            if(acc + tmp == target) {
                ans.push_back(candidate);
            }
            return;
        }
        // 1. keep attaching digit
        if(num > 0) {
            candidate += str[idx];
            find(idx + 1, acc, tmp, num * 10 + str[idx] - '0', prevOp);
            candidate.pop_back();
        }

        ll nextAcc, nextTmp;
        if(prevOp == '*') {
            nextAcc = acc;
            nextTmp = tmp * num;
        } else if(prevOp == '+') {
            nextAcc = acc + tmp;
            nextTmp = num;
        } else {
            nextAcc = acc + tmp;
            nextTmp = -num;
        }

        // 2. cut with 3 types of ops each
        for(int i = 0; i < 3; ++i) {
            char curOp = "+-*"[i];
            candidate += curOp;
            candidate += str[idx];
            find(idx + 1, nextAcc, nextTmp, str[idx] - '0', curOp);
            candidate.pop_back();
            candidate.pop_back();
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        this->str = num;
        this->target = target;
        candidate += num[0];
        find(1, 0, 0, num[0] - '0', '+');
        return ans;
    }
};