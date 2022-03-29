class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) { // s = eceba, k = 2
    if (k == 0) return 0;
    int N = s.size(); // N = 5
    int ans = 0; // 3
    int l = 0;
    unordered_map<char,int> occur; // {e=0, c=0, b=1, a=1}
    int cntUnique = 0; // 2
    for(int r = 0; r < N; ++r) { // l = 3, r = 5
      occur[s[r]]++;
      if (occur[s[r]] == 1) ++cntUnique;
      while (cntUnique > k) {
        occur[s[l]]--;
        if (occur[s[l]] == 0) --cntUnique;
        ++l;
      }
      ans = max(ans, r - l + 1); // 4 - 3 + 1 = 2
    }
    return ans;
  }
};
