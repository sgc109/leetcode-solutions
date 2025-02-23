class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { // nums1 = [1], m = 0, nums2 = [1], n = 1
    //                                                                               ^                         ^    
        int ptr1 = m - 1; // -1
        int ptr2 = n - 1; // 0
        int ptr3 = m + n - 1; // 0
        while(ptr1 >= 0 && ptr2 >= 0) {
            if(nums1[ptr1] < nums2[ptr2]) {
                nums1[ptr3--] = nums2[ptr2--];
            } else {
                nums1[ptr3--] = nums1[ptr1--];
            }
        }
        while(ptr2 >= 0) {
            nums1[ptr3--] = nums2[ptr2--];
        }
    }
};