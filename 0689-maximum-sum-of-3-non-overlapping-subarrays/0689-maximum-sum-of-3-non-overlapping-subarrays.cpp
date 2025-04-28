/*

max1[i] = nums[i..] 에서 합이 가장 큰 1 subarrays with size k -> O(N)
max2[i] = nums[i..] 에서 합이 가장 큰 non-overlapping 2 subarrays with size k -> O(N)
max3[0] -> O(N)

*/
class Solution {
    vector<int> max1;
    vector<int> max2;
    vector<int> max1Idx;
    vector<pair<int,int>> max2Idx;
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int N = nums.size();
        max1 = vector<int>(N + 1, -1);
        max2 = vector<int>(N + 1, -1);
        max1Idx.resize(N + 1);
        max2Idx.resize(N + 1);
        int sum = 0;
        for(int i = N - 1; i >= 0; --i) {
            sum += nums[i];
            if(i + k < N) {
                sum -= nums[i + k];
            }
            if(i + k <= N) {
                max1[i] = max(max1[i + 1], sum);
                if(max1[i] == sum) {
                    max1Idx[i] = i;
                } else {
                    max1Idx[i] = max1Idx[i + 1];
                }
            }
        }
        sum = 0;
        for(int i = N - 1; i >= 0; --i) {
            sum += nums[i];
            if(i + k < N) {
                sum -= nums[i + k];
            }
            if(i + 2 * k <= N) {
                max2[i] = max(max2[i + 1], sum + max1[i + k]);
                if(max2[i] == sum + max1[i + k]) {
                    max2Idx[i] = {i, max1Idx[i + k]};
                } else {
                    max2Idx[i] = max2Idx[i + 1];
                }
            }
        }
        sum = 0;
        int maxSum = -1;
        vector<int> ans;
        for(int i = N - 1; i >= 0; --i) {
            sum += nums[i];
            if(i + k < N) {
                sum -= nums[i + k];
            }
            if(i + 3 * k <= N) {
                maxSum = max(maxSum, sum + max2[i + k]);
                if(maxSum == sum + max2[i + k]) {
                    ans = vector<int>({i, max2Idx[i + k].first, max2Idx[i + k].second});
                }
            }
        }
        return ans;
    }
};