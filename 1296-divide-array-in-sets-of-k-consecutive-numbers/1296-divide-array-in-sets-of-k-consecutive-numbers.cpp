class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> counter;
        for(int num : nums) {
            counter[num]++;
        }
        for(auto [num, cnt] : counter) {
            if(cnt == 0) {
                continue;
            }
            for(int i = num; i < num + k; ++i) {
                if(counter[i] < cnt) {
                    return false;
                }
                counter[i] -= cnt;
            }
        }
        return true;
    }
};