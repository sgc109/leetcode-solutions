class Solution {
public:
/*
nums1 = [1], m = 0
       ^
nums2 = [1], n = 1
       ^
*/
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        --m; // 0
        --n; // -1
        while(n >= 0 || m >= 0) {
            if(m == -1) {
                nums1[m + n + 1] = nums2[n];
                --n;
            } else if(n == -1) {
                break;
            } else if(nums1[m] < nums2[n]) {
                nums1[m + n + 1] = nums2[n];
                --n;
            } else {
                nums1[m + n + 1] = nums1[m];
                --m;
            }
        }
    }
};