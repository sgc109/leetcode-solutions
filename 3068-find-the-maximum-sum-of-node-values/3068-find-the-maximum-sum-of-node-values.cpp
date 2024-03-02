typedef long long ll;

class Solution {
public:
    ll maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int N = size(nums);
        vector<int> bigger, smaller;

        ll sum = 0;
        for(int i = 0; i < N; ++i) {
            sum += nums[i];
            int oldVal = nums[i];
            int newVal = nums[i] ^ k;
            if(oldVal < newVal) {
                bigger.push_back(oldVal - newVal); // delta = 음수로 변환
            } else {
                smaller.push_back(oldVal - newVal); // delta = 음수로 변환
            }
        }
        sort(begin(bigger), end(bigger));
        sort(begin(smaller), end(smaller));
        
        int cntPairs = size(bigger) / 2;
        for(int i = 0; i < cntPairs; ++i) {
            sum += (-bigger[2 * i]);
            sum += (-bigger[2 * i + 1]);
        }
        if(size(bigger) % 2 == 0 || size(smaller) == 0) {
            return sum;
        }
        int d = -bigger.back() -smaller[0];
        if(d > 0) {
            return sum + d;
        }
        return sum;
    }
};