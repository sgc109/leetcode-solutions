class Solution {
public:
    int maximumSwap(int num) {
        vector<vector<int>> digitToIndexes(10, vector<int>());
        string numStr = to_string(num);
        for(int i  = size(numStr) - 1; i >=0 ; --i) {
            digitToIndexes[numStr[i] - '0'].push_back(i);
        }
        
        int maxDigit = 9;
        for(int i = 0; i < size(numStr); ++i) {
            int digit = numStr[i] - '0';

            while(digitToIndexes[maxDigit].size() == 0) {
                maxDigit--;
            }

            if(digit < maxDigit) {
                swap(numStr[i], numStr[digitToIndexes[maxDigit][0]]);
                return stoi(numStr);
            }
            
            digitToIndexes[digit].pop_back();
        }

        return num;
    }
};