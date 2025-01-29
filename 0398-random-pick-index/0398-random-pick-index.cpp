class Solution {
    unordered_map<int, vector<int>> numToIndexes;
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < size(nums); ++i) {
            numToIndexes[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int>& indexes = numToIndexes[target];
        int randomIdx = random() % size(indexes);
        return indexes[randomIdx];
    }
};
