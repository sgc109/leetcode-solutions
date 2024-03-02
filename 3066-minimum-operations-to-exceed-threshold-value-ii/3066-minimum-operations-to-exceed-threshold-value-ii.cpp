
typedef long long ll;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll> pq;
        int N = size(nums);
        for(int i = 0; i < N; ++i) {
            pq.push(-nums[i]);
        }
        while(pq.size() > 1 && -pq.top() < k) {
            ll first = -pq.top();
            pq.pop();
            ll second = -pq.top();
            pq.pop();
            pq.push(-(first * 2 + second));
        }
        return N - pq.size();
    }
};