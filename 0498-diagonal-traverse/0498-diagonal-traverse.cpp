class Solution {
    int du[2][2] = {{0, 1}, {1, 0}};
    int dd[2][2] = {{1, 0}, {0, 1}};
    int R;
    int C;
    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        R  = mat.size();
        C = mat[0].size();
        bool isGoingUp = true;
        int cr = 0;
        int cc = 0;
        vector<int> ans;
        while(cr != R - 1 || cc != C - 1) {
            ans.push_back(mat[cr][cc]);
            if(isGoingUp) {
                int nr = cr - 1;
                int nc = cc + 1;
                if(inRange(nr, nc)) {
                    cr = nr;
                    cc = nc;
                    continue;
                }
                isGoingUp = !isGoingUp;
                nr = cr + du[0][0];
                nc = cc + du[0][1];
                if(inRange(nr, nc)) {
                    cr = nr;
                    cc = nc;
                    continue;
                }
                cr += du[1][0];
                cc += du[1][1];
            } else {
                int nr = cr + 1;
                int nc = cc - 1;
                if(inRange(nr, nc)) {
                    cr = nr;
                    cc = nc;
                    continue;
                }
                isGoingUp = !isGoingUp;
                nr = cr + dd[0][0];
                nc = cc + dd[0][1];
                if(inRange(nr, nc)) {
                    cr = nr;
                    cc = nc;
                    continue;
                }
                cr += dd[1][0];
                cc += dd[1][1];
            }
        }
        ans.push_back(mat[R - 1][C - 1]);
        return ans;
    }
};