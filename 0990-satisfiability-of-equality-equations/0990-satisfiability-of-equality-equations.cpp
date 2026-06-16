class Solution {
    vector<int> par;
    int find(int u) {
        if(par[u] == u) {
            return u;
        }
        return par[u] = find(par[u]);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) {
            return;
        }
        par[a] = b;
    }
public:
    Solution() {
        par.resize(26);
        for(int i = 0; i < 26; ++i) {
            par[i] = i;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        for(auto& e : equations) {
            if(e[1] == '!') {
                continue;
            }
            int a = e[0] - 'a';
            int b = e[3] - 'a';
            merge(a, b);
        }
        for(auto& e : equations) {
            if(e[1] == '=') {
                continue;
            }
            int a = e[0] - 'a';
            int b = e[3] - 'a';
            if(find(a) == find(b)) {
                return false;
            }
        }
        return true;
    }
};