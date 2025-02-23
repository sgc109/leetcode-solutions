class SparseVector {
    unordered_map<int, int> map; // {0 -> 1, 3 -> 2, 4 -> 3} | {1 -> 3, 3 -> 4}
public:
    SparseVector(vector<int> &nums) { // 1,0,0,2,3 | 0,3,0,4,0
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i]) {
                map[i] = nums[i];
            }
        } 
    }

    int getNonZeroCount() {
        return map.size();
    }

    int getValue(int index) {
        return map[index];
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        if(map.size() > vec.getNonZeroCount()) {
            return vec.dotProduct(*this);
        }
        int acc = 0;
        for(auto it : map) {
            acc += vec.getValue(it.first) * it.second;
        }
        return acc;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
