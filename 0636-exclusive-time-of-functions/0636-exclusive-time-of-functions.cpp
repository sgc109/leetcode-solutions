class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans = vector<int>(n, 0);
        stack<pair<int,int>> stack;
        string tmp;
        for(string& log : logs) {
            stringstream ss(log);
            getline(ss, tmp, ':');
            int funcId = stoi(tmp);
            getline(ss, tmp, ':');
            string event = tmp;
            getline(ss, tmp, ':');
            int timestamp = stoi(tmp);
            if(event == "start") {
                stack.push({timestamp, 0});
            } else {
                auto top = stack.top();
                stack.pop();
                int startTime = top.first;
                int totalExecutionOnTop = top.second;
                ans[funcId] += timestamp - startTime + 1 - totalExecutionOnTop;
                if(!stack.empty()) {
                    stack.top().second += timestamp - startTime + 1;
                }
            }
        }
        return ans;
    }
};