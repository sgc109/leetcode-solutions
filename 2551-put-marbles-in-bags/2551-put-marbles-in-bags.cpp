typedef long long ll;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int N = weights.size();
        vector<int> adjSums(N - 1);

        for(int i = 0; i < N - 1; ++i) {
            adjSums[i] = weights[i] + weights[i + 1];
        }

        sort(begin(adjSums), end(adjSums));

        ll minSum = 0;
        ll maxSum = 0;

        for(int i = 0; i < k - 1; ++i) {
            minSum += adjSums[i];
            maxSum += adjSums[N - 2 - i];
        }
        
        return maxSum - minSum;
    }
};