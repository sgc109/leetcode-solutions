class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    int N = nums.size();
    unordered_map<int,int> minIdx;
    minIdx[0] = -1;
    vector<int> psum(N, 0);
    int ans = 0;
    psum[0] = nums[0];
    for(int i = 1; i < N; ++i) {
      psum[i] = psum[i-1] + nums[i];
    }
    for(int i = 0; i < N; ++i) {
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
