class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        
        sort(nums.begin(), nums.end());
        
        int N = int(nums.size());
        for(int i = 0; i < N - 2; i++) {
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            
            int l = i + 1, r = N - 1;
            int target = -nums[i];
            while(l < r) {
                if(l > i + 1 && nums[l - 1] == nums[l]) {
                    l++;
                    continue;
                }
                if(r < N - 1 && nums[r] == nums[r + 1]) {
                    r--;
                    continue;
                }
                int sum = nums[l] + nums[r];
                if(target == sum) {
                    ret.push_back({nums[l], nums[r], nums[i]});
                    l++;
                    r--;
                }
                else if(target > sum) l++;
                else r--;
            }
        }
        
        return ret;
    }
};