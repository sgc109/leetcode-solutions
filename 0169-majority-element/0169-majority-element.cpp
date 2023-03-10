class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = -1;
        int cnt = 0;
        for(int num : nums) {
            if(cnt == 0) {
                ans = num;
                cnt++;
            } else if(ans == num) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return ans;
    }
};