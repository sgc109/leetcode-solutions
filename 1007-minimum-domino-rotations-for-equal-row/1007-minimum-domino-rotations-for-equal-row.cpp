class Solution {
    int topCount[7];
    int bottomCount[7];
    int can[7];
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        can[tops[0]] = 1;
        can[bottoms[0]] = 1;
        int N = tops.size();
        for(int i = 0; i < N; ++i) {
            topCount[tops[i]]++;
            bottomCount[bottoms[i]]++;
            if(tops[0] != tops[i] && tops[0] != bottoms[i]) {
                can[tops[0]] = 0;
            }
            if(bottoms[0] != tops[i] && bottoms[0] != bottoms[i]) {
                can[bottoms[0]] = 0;
            }
        }
        int ans = 20001;
        for(int i = 1; i <= 6; ++i) {
            if(can[i]) {
                ans = min({ans, N - topCount[i], N - bottomCount[i]});
            }
        }

        return ans == 20001 ? -1 : ans;
    }
};