class SparseVector {
public:
    unordered_map<int, int> map; // {0 -> 1, 3 -> 2, 4 -> 3} | {1 -> 3, 3 -> 4}

    SparseVector(vector<int> &nums) { // 1,0,0,2,3 | 0,3,0,4,0
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
        int acc = 0; // 8
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