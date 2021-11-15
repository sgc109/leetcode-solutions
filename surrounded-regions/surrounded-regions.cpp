class Solution {
public:
    int N, M;
    bool in_range(int i, int j){
        return 0 <= i && i < N && 0 <= j && j < M;
    }
    vector<pair<int,int>> backup;
    vector<vector<int>> vis;
    bool poss;
    void dfs(int i, int j, vector<vector<char>>& board){
        backup.push_back({i, j});
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int ni = i + "2110"[k] - '1';
            int nj = j + "1201"[k] - '1';
            if(!in_range(ni, nj) || board[ni][nj] == 'X' || vis[ni][nj]) {
                if(!in_range(ni, nj)) poss = false;
                continue;
            }
            dfs(ni, nj, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        N = board.size();
        M = board[0].size();
        vis = vector<vector<int>>(N, vector<int>(M, 0));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++){
                if(board[i][j] == 'X' || vis[i][j]) continue;
                backup.clear();
                poss = true;
                dfs(i, j, board);
                if(poss) {
                    for(auto p : backup){
                        board[p.first][p.second] = 'X';
                    }
                    backup.clear();
                }
            }
        }
    }
};