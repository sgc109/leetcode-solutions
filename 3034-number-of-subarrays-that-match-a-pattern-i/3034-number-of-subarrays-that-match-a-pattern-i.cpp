class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int N = nums.size();
        int M = pattern.size();
        int ans = 0;
        for(int i = 0; i < N - M; ++i) {
            bool invalid = false;
            for(int j = 0; j < M; ++j) {
                if(pattern[j] == 1) {
                    if(nums[i + j] >= nums[i + j + 1]) {
                        invalid = true;
                        break;
                    }
                } else if(pattern[j] == 0) {
                    if(nums[i + j] != nums[i + j + 1]) {
                        invalid = true;
                        break;
                    }
                } else {
                    if(nums[i + j] <= nums[i + j + 1]) {
                        invalid = true;
                        break;
                    }
                }
            }
            if(!invalid) {
                ++ans;
            }
        }
        return ans;
    }
};