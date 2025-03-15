class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = -1, r = arr.size();
        while(l < r - 1) {
            int m = (l + r) / 2;
            if((m == -1 ? 0 : arr[m]) - (m + 1) < k) {
                l = m;
            } else {
                r = m;
            }
        }
        return k + l + 1;
    }
};