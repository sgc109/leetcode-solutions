class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) {
            return false;
        }
        int first = INT_MAX, second = INT_MAX;
        for(int num : nums) {
            if (second < num) {
                return true;
            } else if (first < num) {
                second = num;
            } else {
                first = num;
            }
        }
        
        return false;
    }
};