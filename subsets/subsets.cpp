class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int N = nums.size();
        for(int i = 0; i < 1 << N; i++) {
            vector<int> v;
            int base = i;
            for(int j = 0; j < N, base > 0; j++, base >>= 1) {
                if(base & 1) {
                    v.push_back(nums[j]);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};