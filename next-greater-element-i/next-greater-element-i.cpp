class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        vector<int> stk;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            int num = nums2[i];
            while(!stk.empty() && stk.back() < num) {
                stk.pop_back();
            }
            if(stk.empty()) {
                nextGreater[num] = -1;
            } else {
                nextGreater[num] = stk.back();
            }
            stk.push_back(num);
        }
        vector<int> ans;
        for(int num : nums1) {
            ans.push_back(nextGreater[num]);
        }
        return ans;
    }
};
