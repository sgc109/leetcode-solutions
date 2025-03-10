// nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]

template<typename T>
class SparseVector {
    vector<pair<int,T> > indexAndVals;
public:
    SparseVector(vector<T> &nums) {
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i]) {
                indexAndVals.push_back({i, nums[i]});
            }
        }
    }
    /*
     [[1,1],[4,2]]
                   ^

     [[0,1],[4,3],[6,4]]
                    ^
    */
    T dotProduct(SparseVector& vec) { // 
        int p1 = 0; // 0
        int p2 = 0;
        T acc = 0; // 6
        while(p1 < indexAndVals.size() && p2 < vec.indexAndVals.size()) {
            auto pair1 = indexAndVals[p1];
            auto pair2 = vec.indexAndVals[p2];
            
            if(pair1.first == pair2.first) {
                acc += pair1.second * pair2.second;
                ++p1;
                ++p2;
            } else if(pair1.first < pair2.first) {
                ++p1;
            } else {
                ++p2;
            }
        }
        return acc;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);