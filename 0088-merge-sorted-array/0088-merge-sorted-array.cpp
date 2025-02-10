class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = m - 1;
        int pos2 = n - 1;
        int pos3 = m + n - 1;

        while(pos1 >= 0 && pos2 >= 0) {
            if(nums1[pos1] <= nums2[pos2]) {
                nums1[pos3--] = nums2[pos2--];
            } else {
                nums1[pos3--] = nums1[pos1--];
            }
        }

        while(pos2 >= 0) {
            nums1[pos3--] = nums2[pos2--];
        }
    }
};