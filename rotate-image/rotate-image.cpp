class Solution {
    int N;
    void rotate4(vector<vector<int>>& matrix, int ci, int cj) {
        int backup = matrix[ci][cj];
        for(int k = 0; k < 4; k++) {
            int ni = cj, nj = N - 1 - ci;
            int tmp = matrix[ni][nj];
            matrix[ni][nj] = backup;
            backup = tmp;
            ci = ni, cj = nj;
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        N = matrix.size();
        int half = N / 2;
        for(int i = 0; i < half; i++) {
            for(int j = i; j < N - 1 - i; j++) {
                rotate4(matrix, i, j);
            }
        }
    }
};
