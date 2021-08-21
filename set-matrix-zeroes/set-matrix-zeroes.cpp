/*
* Time complexity: O(N * M)
* Space complexity: O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        bool isFirstRowZero = false;
        bool isFirstColZero = false;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0) {
                        isFirstRowZero = true;
                    } else {
                        matrix[i][0] = 0;
                    }
                    if(j == 0) {
                        isFirstColZero = true;
                    } else {
                        matrix[0][j] = 0;
                    }
                    
                }
            }
        }
        for(int i = 1; i < M; i++) {
            if(matrix[0][i] == 0) {
                for(int j = 0; j < N; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        for(int i = 1; i < N; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 0; j < M; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(isFirstColZero) {
            for(int i = 0; i < N; i++) {
                matrix[i][0] = 0;
            }
        }
        if(isFirstRowZero) {
            for(int i = 0; i < M; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};
