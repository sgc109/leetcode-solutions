class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> counter;
        for(int num : nums) {
            counter[num]++;
        }
        vector<int> ans;
        for(int num : nums) {
            if(counter[num] == 1 && counter[num - 1] == 0 && counter[num + 1] == 0) {
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};