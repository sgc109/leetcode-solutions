class Solution {
public:
    int maximumGap(vector<int>& nums) {
        long long base = 1;
        
        while(base <= 1e9) {
            vector<vector<int>> buckets = vector<vector<int>>(10, vector<int>());
            int cntLessThanBase = 0;
            for(int num : nums) {
                if(num < base) {
                    ++cntLessThanBase;
                }
                int digit = num / base % 10;
                buckets[digit].push_back(num);
            }
            if(cntLessThanBase == size(nums)) {
                break;
            }
            int pos = 0;
            for(int i = 0; i < 10; ++i) {
                for(int num : buckets[i]) {
                    nums[pos++] = num;
                }
            }
            base *= 10;
        }
        int ans = 0;
        for(int i = 0; i < size(nums) - 1; ++i) {
            ans = max(ans, nums[i + 1] - nums[i]);
        }
        return ans;
    }
};