/*
23 2 4 6 7

23 25 29 35 42
5 1 5 5 0

23 2 6 4 7
23 25 31 35 42
5 1 1 5 0

23 2 6 4 7
23 25 31 35 42
10 12 5 9 3

psum[i] = sum(nums[0]..nums[i])
sum(nums[i]..nums[j]) = psum[j] - psum[i - 1]

*/

class Solution {
// [23,2,4,6,7], k = 6
//       ^
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> firstModIdx; // {0: -1, 5:0, 1:1, }
        firstModIdx[0] = -1;
        int acc = 0; // 29
        for(int i = 0; i < nums.size(); ++i) {
            acc = (acc + nums[i]) % k;
            if(firstModIdx.count(acc)) {
                if(i - firstModIdx[acc] >= 2) {
                    return true;
                }
            } else {
                firstModIdx[acc] = i;
            }
        }
        return false;
    }
};