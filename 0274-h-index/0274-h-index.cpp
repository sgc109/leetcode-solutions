class Solution {
public:
    int hIndex(vector<int>& references) {
        int N = references.size();
        sort(begin(references), end(references));
        for(int i = N; i > 0; --i) {
            int idx = N - i;
            if(references[idx] >= i && (idx == 0 || references[idx - 1] <= i)) {
                return i;
            }
        }
        return 0;
    }
};