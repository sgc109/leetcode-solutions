class Solution {
    int calculateOnlyWithMultiplyDivide(string s) {
        int N = s.size();
        int startIdx = 0;
        vector<int> nums;
        vector<char> operators;
        for(int i = 0; i < N; ++i) {
            if(s[i] == '*' || s[i] == '/') {
                nums.push_back(stoi(s.substr(startIdx, i - startIdx)));
                operators.push_back(s[i]);
                startIdx = i + 1;
            }
        }
        if(startIdx < N) {
            nums.push_back(stoi(s.substr(startIdx, N - startIdx)));
        }
        int ret = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(operators[i - 1] == '*') {
                ret *= nums[i];
            } else {
                ret = (int)(ret / nums[i]);
            }
        }
        return ret;
    }
public:
    int calculate(string initialS) {
        string s = "";
        for(char c : initialS) {
            if(c != ' ') {
                s += c;
            }
        }
        vector<int> chunkResults;
        vector<char> operators;
        
        int N = s.size();
        int startIdx = 0;
        bool multiplyDivideExist = false;
        for(int i = 0; i < N; ++i) {
            if(s[i] == '+' || s[i] == '-') {
                string chunk = s.substr(startIdx, i - startIdx);
                if(!multiplyDivideExist) {
                    chunkResults.push_back(stoi(chunk));
                } else {
                    chunkResults.push_back(calculateOnlyWithMultiplyDivide(chunk));
                }
                operators.push_back(s[i]);
                startIdx = i + 1;
                multiplyDivideExist = false;
            } else if(s[i] == '*' || s[i] == '/') {
                multiplyDivideExist = true;
            }
        }
        if(startIdx < N) {
            string chunk = s.substr(startIdx, N - startIdx);
            if(!multiplyDivideExist) {
                chunkResults.push_back(stoi(chunk));
            } else {
                chunkResults.push_back(calculateOnlyWithMultiplyDivide(chunk));
            }
        }
        int ret = chunkResults[0];
        for(int i = 1; i < chunkResults.size(); ++i) {
            if(operators[i - 1] == '+') {
                ret += chunkResults[i];
            } else {
                ret -= chunkResults[i];
            }
        }
        return ret;
    }
};