typedef long long ll;

class Solution {
public:
    vector<ll> minOperations(vector<int>& nums, vector<int>& queries) {
        int N = size(nums);
        sort(begin(nums), end(nums));
        
        vector<ll> psum(N + 1);
        for(int i = 0; i < N; ++i) {
            psum[i+1] = psum[i] + nums[i];
        }
                
        vector<ll> results;
        for(ll query : queries) {
            int idx = lower_bound(begin(nums), end(nums), query) - begin(nums);
            
            ll leftSum = idx * query - psum[idx];
            ll rightSum = psum[N] - psum[idx] - (N - idx) * query;
            
            results.push_back(leftSum + rightSum);
        }
        
        return results;
    }
};