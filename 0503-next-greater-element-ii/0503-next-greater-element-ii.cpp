/*
Took: 10m 15s
Time: O(N)
Space: O(N)
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        vector<int> stk;
        vector<int> ans(N);
        for (int i = N - 1; i >= 0; --i) {
            stk.push_back(nums[i]);
        }
        for (int i = N - 1; i >= 0; --i) {
            while (stk.size() > 0 && stk.back() <= nums[i]) {
                stk.pop_back();
            }
            if (stk.size() == 0) {
                ans[i] = -1;
            } else {
                ans[i] = stk.back();
            }
            stk.push_back(nums[i]);
        }

        return ans;
    }
};