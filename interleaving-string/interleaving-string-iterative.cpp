/*
N: len(s1)
M: len(s2) 일 때,

Time Complexity: O(NM)
Space Complexity: O(NM)

dp[i][j]: s1[..i] 와 s2[..j] 를 interleaving 해서 s3[..i+j] 를 만들 수 있는지 여부(1-base indexing 기준)

s1 과 s2 각각에 대해 포인터를 두고, s3[i+j] 와 맞출 문자로 현재 두 포인터가 각각 가리키는 두 문자 중 하나를 고를 수 있으므로, 아래와 같은 점화식이 나온다.
*/

class Solution {
    bool dp[101][101];
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }
        for(int i = 0; i <= s1.size(); i++) {
            for(int j = 0; j <= s2.size(); j++) {
                dp[i][j] = ((i > 0 && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) 
                            || (j > 0 && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1])
                            || (i == 0 && j == 0));
            }
        }
        
        return dp[s1.size()][s2.size()];
    }
};
