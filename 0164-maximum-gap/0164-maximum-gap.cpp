class Solution {
    int pow[10];
    void bucketSort(vector<int>& sorted, vector<int> nums, int baseIdx, int pos) {
        if(size(nums) == 0) {
            return;
        }
        if(pos == -1) {
            for(int i = 0; i < size(nums); ++i) {
                sorted[baseIdx + i] = nums[i];
            }
            return;
        }
        vector<vector<int>> bucket = vector<vector<int>>(10, vector<int>());
        for(int num : nums) {
            int digit = (num / pow[pos]) % 10;
            bucket[digit].push_back(num);
        }
        int nextBaseIdx = baseIdx;
        for(int i = 0; i < 10; ++i) {
            bucketSort(sorted, bucket[i], nextBaseIdx, pos - 1);
            nextBaseIdx += size(bucket[i]);
        }
    }
public:
    int maximumGap(vector<int>& nums) {
        if(size(nums) == 1) {
            return 0;
        }
        pow[0] = 1;
        for(int i = 1; i <= 9; ++i) {
            pow[i] = pow[i - 1] * 10;
        }
        vector<int> sorted(size(nums));
        bucketSort(sorted, nums, 0, 9);
        int ans = 0;
        for(int i = 0; i < size(sorted) - 1; ++i) {
            ans = max(ans, sorted[i + 1] - sorted[i]);
        }

        return ans;
    }
};