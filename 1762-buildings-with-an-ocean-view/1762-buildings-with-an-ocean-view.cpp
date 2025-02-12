class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        int N = heights.size();
        int maxOnRight = -1;
        for(int i = N - 1; i >= 0; --i) {
            if(heights[i] > maxOnRight) {
                ans.push_back(i);
            }
            maxOnRight = max(maxOnRight, heights[i]);
        }
    
        reverse(ans.begin(), ans.end());

        return ans;
    }
};