class Solution {
    pair<int, int> solve(int l, int r, int k, vector<int>& nums) {
        if(l == r) {
            int cntBetween = nums[l + 1] - nums[l] - 1;
            if(cntBetween >= k) {
                return {nums[l] + k, -1};
            } else {
                return {-1, cntBetween};
            }
        }
        int m = (l + r) / 2;
        auto leftRes = solve(l, m, k, nums);
        if(leftRes.first != -1) {
            return leftRes;
        }

        auto rightRes = solve(m + 1, r, k - leftRes.second, nums);
        if(rightRes.first != -1) {
            return rightRes;
        }
        return {-1, leftRes.second + rightRes.second};
    }
public:
    int missingElement(vector<int>& nums, int k) {
        if(nums.size() == 1) {
            return nums[0] + k;
        }
        auto res = solve(0, size(nums) - 2, k, nums);
        if(res.first != -1) {
            return res.first;
        } else {
            return nums.back() + k - res.second;
        }
    }
};