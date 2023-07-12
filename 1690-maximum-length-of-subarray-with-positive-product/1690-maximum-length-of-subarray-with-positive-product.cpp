class Solution {
    int maxLenWithNon0s(int s, int e, vector<int>& nums) {
        printf("s: %d, e: %d\n", s, e);
        if(s > e) {
            return 0;
        }
        int N = nums.size();
        int len = e - s + 1;
        int firstNegativeIdx = -1;
        int lastNegativeIdx = -1;
        int cntNegatives = 0;
        for(int i = s; i <= e; ++i) {
            if(nums[i] < 0) {
                ++cntNegatives;
                if(firstNegativeIdx == -1) {
                    firstNegativeIdx = i;
                }
            }
        }
        for(int i = e; i >= s; --i) {
            if(nums[i] < 0) {
                lastNegativeIdx = i;
                break;
            }
        }
        if(cntNegatives % 2 == 0) {
            return len;
        }
        
        return max(e - firstNegativeIdx, lastNegativeIdx - s);
    }
public:
    int getMaxLen(vector<int>& nums) {
        int N = nums.size();
        int last = -1;
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            if(nums[i] == 0 && last != -1) {
                ans = max(ans, maxLenWithNon0s(last, i-1, nums));
                last = -1;
            }
            if(nums[i] != 0 && last == -1) {
                last = i;
            }
        }
        if(last != -1) {
            ans = max(ans, maxLenWithNon0s(last, N-1, nums));
        }
        return ans;
    }
};


/*
1. split to sub-arrays based on 0s
2. if # of negatives is even, return size of the array
3. else if # of negatives is odd, return max(index of last negative, size - index of first negative - 1)
*/