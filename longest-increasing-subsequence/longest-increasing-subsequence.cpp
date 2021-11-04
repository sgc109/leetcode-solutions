class Solution {
    vector<int> lis;
public:
    int lengthOfLIS(vector<int>& nums) {
        for(int num : nums) {
            int pos = lower_bound(begin(lis), end(lis), num) - begin(lis);
            if(pos == lis.size()) {
                lis.push_back(num);
            } else {
                lis[pos] = num;
            }
        }
        return lis.size();
    }
};