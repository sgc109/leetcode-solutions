class Solution {
    int N, M;
    unordered_map<int, int> counter;
    bool isPrime(int x) {
        for(int i = 2; i * i <= x; ++i) {
            if(x % i == 0) {
                return false;
            }
        }
        return true;
    }
    bool inRange(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < M;
    }
    void go(int r, int c, vector<vector<int>>& mat) {
        for(int k = 0; k < 8; ++k) {
            int curNum = mat[r][c];
            int dr = "00122210"[k] - '1';
            int dc = "12221000"[k] - '1';
            
            int nr = r + dr;
            int nc = c + dc;
            while(inRange(nr, nc)) {
                curNum = curNum * 10 + mat[nr][nc];
                if(isPrime(curNum)) {
                    counter[curNum]++;
                }
                
                nr += dr;
                nc += dc;
            }
        }
    }
    
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        N = mat.size();
        M = mat[0].size();
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                go(i, j, mat);
            }
        }
        int mostFreqVal = -1;
        int freq = 0;
        for(auto it : counter) {
            if(freq < it.second) {
                mostFreqVal = it.first;
                freq = it.second;
            } else if(freq == it.second && mostFreqVal < it.first) {
                mostFreqVal = it.first;
            }
        }
        return mostFreqVal;
    }
};