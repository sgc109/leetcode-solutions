class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        unordered_map<int, int> in;
        unordered_map<int, int> counter;

        for(int num : changed) {
            counter[num]++;
            in[num * 2]++;
        }
        if(counter[0] % 2) {
            return vector<int>();
        }
        for(int i = 0; i < counter[0] / 2; ++i) {
            ans.push_back(0);
        }
        for(int num : changed) {
            if(in[num] || num == 0) {
                continue;
            }
            int cur = num;
            while(counter[cur]) {
                if(counter[cur * 2] < counter[cur]) {
                    return vector<int>();
                }
                for(int i = 0; i < counter[cur]; ++i) {
                    ans.push_back(cur);       
                }
                counter[cur * 2] -= counter[cur];
                counter[cur] = 0;
                if(counter[cur * 2] == 0) {
                    cur *= 4;
                } else {
                    cur *= 2;
                }
            }
        }

        return ans;
    }
};