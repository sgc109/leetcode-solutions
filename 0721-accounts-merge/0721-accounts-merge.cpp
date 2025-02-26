class Solution {
    int N;
    vector<int> parents;
    vector<int> sizes;
    int find(int u) {
        return parents[u] = parents[u] == u ? u : find(parents[u]);
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) {
            return;
        }
        if(sizes[u] > sizes[v]) {
            swap(u, v);
        }
        parents[u] = v;
        sizes[v] += sizes[u];
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        N = accounts.size();
        parents = vector<int>(N);
        sizes = vector<int>(N, 1);
        for(int i = 0; i < N; ++i) {
            parents[i] = i;
        }
        unordered_map<string, vector<int>> emailToIndices;
        for(int i = 0; i < N; ++i) {
            for(int j = 1; j < accounts[i].size(); ++j) {
                auto email = accounts[i][j];
                emailToIndices[email].push_back(i);
            }
        }
        for(auto it : emailToIndices) {
            auto indices = it.second;
            for(int i = 0; i < indices.size() - 1; ++i) {
                merge(indices[i], indices[i + 1]);
            }
        }
        unordered_map<int, set<string>> groupIdToEmails;
        for(int i = 0; i < N; ++i) {
            int groupId = find(i);
            for(int j = 1; j < accounts[i].size(); ++j) {
                groupIdToEmails[groupId].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> ans;
        for(auto it : groupIdToEmails) {
            int groupId = it.first;
            set<string> emails = it.second;
            vector<string> account({accounts[groupId][0]});
            account.insert(account.end(), emails.begin(), emails.end());
            ans.push_back(account);
        }
        return ans;
    }
};