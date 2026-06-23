class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        bool isFirstTopCommon = true;
        bool isFirstBottomCommon = true;

        int N = tops.size();

        int cntFirstTop = 1;
        int cntFirstBottom = 1;

        for(int i = 1; i < N; ++i) {
            if(tops[i] != tops[0] && bottoms[i] != tops[0]) {
                isFirstTopCommon = false;
            }

            if(bottoms[i] != bottoms[0] && tops[i] != bottoms[0]){
                isFirstBottomCommon = false;
            }
        }

        if(!isFirstTopCommon && !isFirstBottomCommon) {
            return -1;
        }

        int ans = 20001;
        if(isFirstTopCommon) {
            int up = 0;
            int down = 1;
            for(int i = 1; i < N; ++i) {
                if(tops[0] != tops[i]) {
                    ++up;
                }
                if(tops[0] != bottoms[i]) {
                    ++down;
                }
            }
            ans = min(up, down);
        }

        if(isFirstBottomCommon) {
            int up = 1;
            int down = 0;
            for(int i = 1; i < N; ++i) {
                if(bottoms[0] != bottoms[i]) {
                    ++down;
                }
                if(bottoms[0] != tops[i]) {
                    ++up;
                }
            }
            ans = min({ans, up, down});
        }

        return ans;
    }
};