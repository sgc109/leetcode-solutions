class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(begin(changed), end(changed));
        unordered_map<int, int> counter;
        vector<int> ans;
        for(int num : changed) {
            if(num % 2 == 0 && counter.find(num / 2) != counter.end()) {
                counter[num / 2]--;
                ans.push_back(num / 2);
                if(counter[num / 2] == 0) {
                    counter.erase(num / 2);
                }
            } else {
                counter[num]++;
            }
        }
        if(counter.size() > 0) {
            return vector<int>();
        }
        return ans;
    }
};