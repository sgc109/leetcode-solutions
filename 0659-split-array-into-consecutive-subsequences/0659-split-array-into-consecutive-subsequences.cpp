class Solution {
/*
original counter = {1:1, 2:1, 3:2, 4:1, 5:1}
updated counter = {1:0, 2:0, 3:0, 4:0, 5:0}
endCnt = {3:1, 5:1}
*/
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> counter;
        unordered_map<int, int> endCnt;
        for(int num : nums) {
            counter[num]++;
        }
        for(int num : nums) { // num = 5, cnt = 0
            while(counter[num]-- > 0) {
                if(endCnt[num - 1] > 0) {
                    endCnt[num - 1]--;
                    endCnt[num]++;
                } else if(counter[num + 1] > 0 && counter[num + 2] > 0) {
                    counter[num + 1]--;
                    counter[num + 2]--;
                    endCnt[num + 2]++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};