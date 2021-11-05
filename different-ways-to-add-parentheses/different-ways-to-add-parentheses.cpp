class Solution {
    bool isOp(char c) {
        return c == '*' || c == '+' || c == '-';
    }
    
    pair<vector<int>, vector<char>> parse(string expr) {
        vector<int> nums;
        vector<char> ops;
        
        int acc = 0;
        for(char c : expr) {
            if(isOp(c)) {
                nums.push_back(acc);
                acc = -1;
                ops.push_back(c);
            } else {
                if(acc == -1) {
                    acc = c - '0';
                } else {
                    acc = acc * 10 + c - '0';
                }
            }
        }
        nums.push_back(acc);
        
        return make_pair(nums, ops);
    }
    
    int calc(int num1, int num2, char op) {
        if(op == '+') return num1 + num2;
        else if(op == '-') return num1 - num2;
        assert(op == '*');
        return num1 * num2;
    }
    
    void solve(vector<int>& nums, vector<char>& ops, vector<int>& ans, int prv) {
        if(nums.size() == 1) {
            ans.push_back(nums[0]);
            return;
        }
        vector<int> nxtNums;
        vector<char> nxtOps;
        for(int i = 1; i < nums.size(); ++i) {
            nxtNums.push_back(nums[i]);
        }
        for(int i = 1; i < ops.size(); ++i) {
            nxtOps.push_back(ops[i]);
        }
        for(int i = 0; i < ops.size(); ++i) {
            nxtNums[i] = calc(nums[i], nums[i + 1], ops[i]);
            if(i >= prv - 1) {
                solve(nxtNums, nxtOps, ans, i);
            }
            nxtNums[i] = nums[i];
            if(i < ops.size() - 1) {
                nxtOps[i] = ops[i];
            }
        }
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        auto parsed = parse(expression);
        vector<int> nums = parsed.first;
        vector<char> ops = parsed.second;
        
        assert(nums.size() == ops.size() + 1);
        
        vector<int> ans;
        solve(nums, ops, ans, -1);
        
        return ans;
    }
};