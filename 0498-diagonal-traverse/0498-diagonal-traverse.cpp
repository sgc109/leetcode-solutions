class Solution {
    int R, C;
    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        R = mat.size();
        C = mat[0].size();

        vector<int> ans;

        int r = 0, c = 0;
        int dr = -1, dc = 1;
        while(r != R - 1 || c != C - 1) {
            while(true) {
                ans.push_back(mat[r][c]);
                if(!inRange(r + dr, c + dc)) {
                    break;
                }
                r += dr, c += dc;
            }
            if(dr == -1) { // going up & right
                if(inRange(r, c + 1)) { // try to go right
                    c++;
                } else {
                    r++;
                }
            } else { // going down & left
                if(inRange(r + 1, c)) { // try to go down
                    r++;
                } else {
                    c++;
                }
            }
            dr *= -1;
            dc *= -1;
        }
        ans.push_back(mat[R - 1][C - 1]);

        return ans;
    }
};