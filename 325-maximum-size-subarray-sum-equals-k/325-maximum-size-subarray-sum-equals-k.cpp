class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) { // nums = [1,-1,5,-2,3], k = 3
    int N = nums.size();
    unordered_map<int,int> minIdx; // {0=-1, 1=0, 3=3, 5=2, 6=4}
    minIdx[0] = -1;
    vector<int> psum(N, 0); // psum = [1, 0, 5, 3, 6]
    int ans = 0; // 4
    psum[0] = nums[0];
    for(int i = 1; i < N; ++i) {
      psum[i] = psum[i-1] + nums[i];
    }
    for(int i = 0; i < N; ++i) { // i = 4
      if (minIdx.count(psum[i] - k) > 0) {
        int len = i - minIdx[psum[i] - k];
        ans = max(ans, len);
      }
      if (minIdx.count(psum[i]) == 0) {
        minIdx[psum[i]] = i;
      }
    }
    return ans;
  }
};
