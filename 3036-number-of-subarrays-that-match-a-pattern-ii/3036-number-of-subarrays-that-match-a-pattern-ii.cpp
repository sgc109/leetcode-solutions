class Solution {
    vector<int> calcZArray(vector<int>& base, vector<int>& pattern) {
        vector<int> zArray = vector<int>(size(base), 0);

        int n = size(base);
        int l, r = 0;
        for(int i = 1; i < n; ++i) {
            if(i > r) {
                l = r = i;
                while(r < n && base[r] == base[r - l]) ++r;
                zArray[i] = r - l;
                --r;
            } else {
                int k = i - l;
                if(zArray[k] < r - i + 1) {
                    zArray[i] = zArray[k];
                } else {
                    l = i;
                    while(r < n && base[r] == base[r - l]) ++r;
                    zArray[i] = r - l;
                    --r;
                }
            }
        }

        return zArray;
    }

    vector<int> makeNewBase(vector<int>& base, vector<int>& pattern) {
        vector<int> newBase(begin(pattern), end(pattern));
        newBase.push_back(999);
        newBase.insert(end(newBase), begin(base), end(base));
        return newBase;
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int> trans(size(nums) - 1);
        for(int i = 0; i < size(nums) - 1; ++i) {
            if(nums[i] < nums[i + 1]) {
                trans[i] = 1;
            } else if(nums[i] == nums[i + 1]) {
                trans[i] = 0;
            } else {
                trans[i] = -1;
            }
        }
        vector<int> base = makeNewBase(trans, pattern);
        vector<int> zArray = calcZArray(base, pattern);
        int ans = 0;
        for(int i = size(pattern) + 1; i < size(base); ++i) {
            ans += (zArray[i] == size(pattern));
        }
        
        return ans;
    }
};