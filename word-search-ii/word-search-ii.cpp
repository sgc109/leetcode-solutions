class Solution {
    int R, C;
    vector<vector<char>> board;
    vector<string> ans;
    vector<string> words;
    
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
    
    void dfs(int r, int c, Node* node) {
        if(r < 0 || r >= R || c < 0 || c >= C || board[r][c] == '#') return;
        
        Node* next = node->adj[board[r][c] - 'a'];
        if(next == 0) return;
        
        if(next->strId != -1) {
            ans.push_back(words[next->strId]);
            next->strId = -1;
        }
        
        char back = board[r][c];
        board[r][c] = '#';
        
        dfs(r+1, c, next);
        dfs(r-1, c, next);
        dfs(r, c+1, next);
        dfs(r, c-1, next);
        
        board[r][c] = back;
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
                dfs(i, j, trie);
            }
        }
        
        return ans;
    }
};
