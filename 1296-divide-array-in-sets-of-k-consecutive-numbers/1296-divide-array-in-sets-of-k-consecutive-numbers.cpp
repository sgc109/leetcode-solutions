class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) { // k = 4
        map<int, int> counter; // {1:1, 2:1, 3:2, 4:2, 5:1, 6:1}
        queue<pair<int, int>> delta; // {4:-1, }


        for(int num : nums) {
            counter[num]++;
        }
        
        int maxVal = counter.rbegin()->first; // maxVal = 6
        int minus = 0; // minus = 1
        int prev = -1; // prev = 2
        for(auto [num, cnt] : counter) { // num = 2, cnt = 1
            if(prev != -1 && prev != num - 1 && minus > 0) {
                return false;
            }
            prev = num;
            if(cnt < minus) {
                return false;
            } else if(cnt > minus) {
                int add = cnt - minus; // add = 1
                if(num + k > maxVal + 1 || counter[num + k - 1] == 0) {
                    return false;
                }
                minus = cnt;
                delta.push({num + k - 1, -add});
            }
            while(!delta.empty() && delta.front().first <= num) {
                minus += delta.front().second;
                delta.pop();
            }
        }
        return true;
    }
};