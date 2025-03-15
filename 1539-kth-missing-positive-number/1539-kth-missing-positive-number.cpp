class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); ++i) {
            if(k + i < arr[i]) {
                return k + i;
            }
        }
        return k + arr.size();
    }
};