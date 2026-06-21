class Solution {
    int getAtMostK(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int, int> counter;
        int l = 0;
        for(int r = 0; r < nums.size(); ++r) {
            counter[nums[r]]++;
            while(counter.size() > k) {
                counter[nums[l]]--;
                if(counter[nums[l]] == 0) {
                    counter.erase(counter.find(nums[l]));
                }
                ++l;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return getAtMostK(nums, k) - getAtMostK(nums, k - 1);
    }
};