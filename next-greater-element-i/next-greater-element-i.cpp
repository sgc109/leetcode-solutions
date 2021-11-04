class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> stk;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            int num = nums2[i];
            while(!stk.empty() && stk.top() < num) {
                stk.pop();
            }
            if(stk.empty()) {
                nextGreater[num] = -1;
            } else {
                nextGreater[num] = stk.top();
            }
            stk.push(num);
        }
        vector<int> ans;
        for(int num : nums1) {
            ans.push_back(nextGreater[num]);
        }
        return ans;
    }
};