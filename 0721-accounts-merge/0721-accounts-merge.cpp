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
        // 1. Initialize DSU - O(N), O(N)
        N = accounts.size();
        parents = vector<int>(N);
        sizes = vector<int>(N, 1);
        for(int i = 0; i < N; ++i) {
            parents[i] = i;
        }

        // 2. Merge accounts with common email - O(NK), O(NK)
        unordered_map<string, int> emailToMemberId;
        for(int i = 0; i < N; ++i) {
            for(int j = 1; j < accounts[i].size(); ++j) {
                auto email = accounts[i][j];
                if(emailToMemberId.count(email)) {
                    merge(emailToMemberId[email], i);
                } else {
                    emailToMemberId[email] = i;
                }
            }
        }

        // 3. Collect all emails for each group - O(NKLlogNK), O(NKL)
        unordered_map<int, set<string>> groupIdToEmails;
        for(int i = 0; i < N; ++i) {
            int groupId = find(i);
            for(int j = 1; j < accounts[i].size(); ++j) {
                groupIdToEmails[groupId].insert(accounts[i][j]);
            }
        }

        // 4. Convert to answer format - O(NKL), O(NKL)
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