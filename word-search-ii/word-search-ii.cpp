class Solution {
    int R, C;
    vector<vector<char>> board;
    vector<string> ans;
    vector<string> words;
    
    int dy[4] = {0, -1, 1, 0};
    int dx[4] = {-1, 0, 0, 1};
    
    struct Node {
        Node* adj[26] = {0, };
        int strId = -1;
        
        void insert(const char* s, int id) {
            if(s[0] == 0) {
                strId = id;
                return;
            }
            int idx = s[0] - 'a';
            if(adj[idx] == 0) {
                adj[idx] = new Node();
            }
            adj[idx]->insert(s + 1, id);
        }
    };
    
    bool inRange(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
    
    int getHash(int r, int c) {
        return r * 12 + c;
    }
    
    void dfs(int ci, int cj, Node* node) {
        if(node == 0) return;
        char back = board[ci][cj];
        board[ci][cj] = ' ';
        if(node->strId != -1) {
            ans.push_back(words[node->strId]);
            node->strId = -1;
        }
        for(int i = 0; i < 4; ++i) {
            int ni = ci + dy[i];
            int nj = cj + dx[i];
            if(!inRange(ni, nj) || board[ni][nj] == ' ') continue;
            Node* nextNode = node->adj[board[ni][nj] - 'a'];
            dfs(ni, nj, nextNode);
        }
        board[ci][cj] = back;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->R = board.size();
        this->C = board[0].size();
        this->board = board;
        this->words = words;
        Node* trie = new Node();
        for(int i = 0; i < words.size(); ++i) {
            trie->insert(words[i].c_str(), i);
        }
        
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                dfs(i, j, trie->adj[board[i][j] - 'a']);
            }
        }
        
        return ans;
    }
};