class Solution {
    void updateMin4(vector<int>& min4, int newNum) {
        int cur = newNum;
        for(int i = 0; i < 4; ++i) {
            if(min4[i] > cur) {
                swap(min4[i], cur);
            }
        }
    }

    void updateMax4(vector<int>& max4, int newNum) {
        int cur = newNum;
        for(int i = 0; i < 4; ++i) {
            if(max4[i] < cur) {
                swap(max4[i], cur);
            }
        }
    }
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) {
            return 0;
        }
        int maxVal = 1e9;
        vector<int> min4({maxVal, maxVal, maxVal, maxVal});
        vector<int> max4({-maxVal, -maxVal, -maxVal, -maxVal});

        for(int num : nums) {
            updateMin4(min4, num);
            updateMax4(max4, num);
        }

        int ans = 2e9;
        for(int i = 0; i < 4; ++i) {
            int diff = max4[i] - min4[3 - i];
            ans = min(ans, diff);
        }
        
        return ans;
    }
};