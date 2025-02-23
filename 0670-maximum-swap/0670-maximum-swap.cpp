class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        unordered_map<int, deque<int>> digitToIndices;
        for(int i = 0; i < numStr.size(); ++i) {
            digitToIndices[numStr[i] - '0'].push_back(i);
        }

        for(int i = 0; i < numStr.size(); ++i) {
            for(int j = 9; j > numStr[i] - '0'; --j) {
                if(!digitToIndices[j].empty()) {
                    int idxToSwap = digitToIndices[j].back();
                    swap(numStr[i], numStr[idxToSwap]);
                    return stoi(numStr);
                }
            }
            digitToIndices[numStr[i] - '0'].pop_front();
        }
        return num;
    }
};