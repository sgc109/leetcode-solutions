typedef long long ll;

class Solution {
    int N;
    int M;
    int dp[63][(1<<16)+3];
    ll members[63][(1<<16)+3] = {0, };
    vector<int> bitPeople;

    int go(int personId, int chosen) {
        if(personId == N) {
            return chosen == ((1<<M)-1) ? 0 : N+1;
        }

        int& cache = dp[personId][chosen];
        if(cache != -1) {
            return cache;
        }

        int ret = N + 1;

        // 1. choose
        ret = go(personId + 1, chosen | bitPeople[personId]) + 1;
        members[personId][chosen] = members[personId+1][chosen | bitPeople[personId]] | (1ll<<personId);

        // 2. not choose
        int ans2 = go(personId + 1, chosen);
        if(ans2 < ret) {
            ret = ans2;
            members[personId][chosen] = members[personId+1][chosen];
        }
        
        return cache = ret;
    }
public:
    vector<int> smallestSufficientTeam(vector<string> reqSkills, vector<vector<string>> people) {
        memset(dp,-1,sizeof(dp));
        bitPeople = vector<int>();
        N = people.size();
        M = reqSkills.size();

        // 1. make dictionary
        unordered_map<string, int> skillIds;

        for(int i = 0; i < reqSkills.size(); ++i) {
            auto skill = reqSkills[i];
            skillIds[skill] = i;
        }

        // 2. transform people to bitmask array
        for(auto person : people) {
            int state = 0;
            for(auto skill : person) {
                state |= (1 << skillIds[skill]);
            }
            bitPeople.push_back(state);
        }

        // 3. DP
        go(0, 0);


        // 4. calculate final ans
        vector<int> ans;
        for(int i = 0; i < N; ++i) {
            ll chosenMembers = members[0][0];
            if(chosenMembers & (1ll << i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};