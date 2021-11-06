class NumArray {
    int nodeSum[90003] = {0, };
    int size;
    void updateTree(int idx, int diff) {
        int pos = idx + 1;
        while(pos <= size) {
            nodeSum[pos] += diff;
            pos += pos & -pos;
        }
    }
    
    int query(int idx) {
        int pos = idx + 1;
        int ret = 0;
        while(pos > 0) {
            ret += nodeSum[pos];
            pos -= pos & -pos;
        }
        return ret;
    }
public:
    NumArray(vector<int>& nums) {
        int N = nums.size();
        size = 1;
        while(size < N) {
            size *= 2;
        }
        for(int i = 0; i < nums.size(); ++i) {
            updateTree(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int oldVal = query(index) - query(index-1);
        updateTree(index, val - oldVal);
    }
    
    int sumRange(int left, int right) {
        return query(right) - query(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */