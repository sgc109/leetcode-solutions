class Solution {
	int dy[4] = {1, 0, 0, -1};
	int dx[4] = {0, 1, -1, 0};
	
	int W, H;
	vector<vector<bool>> visited;
	vector<vector<char>> grid;

	bool in_range(int r, int c){
		return 0 <= r && r < H && 0 <= c && c < W;
	}

	void dfs(int r, int c) {
		if(visited[r][c]) return;
		visited[r][c] = true;

		for(int k = 0; k < 4; k++) {
			int nr = r + dy[k];
			int nc = c + dx[k];
			if(!in_range(nr, nc) || grid[nr][nc] == '0') continue;
			dfs(nr, nc);
		}
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		if(grid.size() == 0) return 0;

		this->grid = grid;
		H = grid.size();
		W = grid[0].size();

		visited = vector<vector<bool>>(H, vector<bool>(W, false));

		int ans = 0;
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				if(grid[i][j] == '1' && !visited[i][j]) {
					ans++;
					dfs(i, j);
				}
			}
		}
		
		return ans;
	}
};
