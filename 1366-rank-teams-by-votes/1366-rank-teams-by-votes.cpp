class Solution {
    struct PositionCounter {
        char team;
        int counts[26] = {0, };

        bool operator<(const PositionCounter &rhs) const {
            for(int i = 0; i < 26; ++i) {
                if(counts[i] != rhs.counts[i]) {
                    return counts[i] > rhs.counts[i];
                }
            }
            return team < rhs.team;
        }

        PositionCounter(char team) {
            this->team = team;
        }
    };
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, PositionCounter*> teamToCounter;
        
        for(int i = 0; i < 26; ++i) {
            char team = 'A' + i;
            teamToCounter[team] = new PositionCounter(team);
        }

        for(auto vote : votes) {
            for(int i = 0; i < vote.size(); ++i) {
                int team = vote[i];
                auto counter = teamToCounter[team];
                counter->counts[i]++;
            }
        }
        vector<PositionCounter> counters;
        for(auto keyAndcounter : teamToCounter) {
            counters.push_back(*keyAndcounter.second);
        }
        sort(begin(counters), end(counters));

        string ans = "";
        for(int i = 0; i < votes[0].size(); ++i) {
            ans += counters[i].team;
        }

        return ans;
    }
};