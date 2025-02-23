class Solution {
public:
    int maximumSwap(int num) {
        vector<int> lastIndex = vector<int>(10, -1);
        string numStr = to_string(num);
        for(int i = 0; i < numStr.size(); ++i) {
            lastIndex[numStr[i] - '0'] = i;
        }
        for(int i = 0; i < numStr.size(); ++i) {
            for(int j = 9; j > numStr[i] - '0'; --j) {
                if(i < lastIndex[j]) {
                    swap(numStr[i], numStr[lastIndex[j]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};
