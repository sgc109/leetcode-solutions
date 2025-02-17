class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIdx;
        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            auto it = lastIdx.find(num);
            if(it != lastIdx.end()) {
                if(i - it->second <= k) {
                    return true;
                }
            }
            lastIdx[num] = i;
        }
        return false;
    }
};