class SparseVector {
public:
    unordered_map<int, int> map;

    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i]) {
                map[i] = nums[i];
            }
        } 
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        auto map1 = this->map;
        auto map2 = vec.map;
        if(map1.size() > map2.size()) {
            swap(map1, map2);
        }
        int acc = 0;
        for(auto it : map1) {
            acc += map2[it.first] * it.second;
        }
        return acc;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);