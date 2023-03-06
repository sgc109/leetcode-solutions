class Solution {
public:
    vector<int> go(int l, int r, vector<int>& nums, vector<char>& ops) {
        if(l == r) {
            return vector<int>({nums[l]});
        }
        vector<int> ans;
        for(int i = l; i < r; ++i) {
            vector<int> ansL = go(l, i, nums, ops);
            vector<int> ansR = go(i + 1, r, nums, ops);
            for(int numL : ansL) {
                for(int numR : ansR) {
                    if(ops[i] == '+') {
                        ans.push_back(numL + numR);
                    } else if(ops[i] == '-') {
                        ans.push_back(numL - numR);
                    } else {
                        ans.push_back(numL * numR);
                    }
                }
            }
        }
        return ans;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> ops;
        
        int acc = 0;
        for(char c : expression) {
            if(c == '*' | c == '-' || c == '+') {
                if(acc > 0) {
                    nums.push_back(acc);
                    acc = 0;
                }
                ops.push_back(c);
            } else {
                acc = acc * 10 + c - '0';
            }
        }
        nums.push_back(acc);
        
        vector<int> ans = go(0, nums.size() - 1, nums, ops);
        sort(begin(ans), end(ans));
        
        return ans;
    }
};