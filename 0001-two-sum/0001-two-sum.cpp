class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(target - nums[i])) {
                ret = {mp[target - nums[i]], i};
                break;
            }
            mp[nums[i]] = i;
        }
        
        return ret;
    }
};