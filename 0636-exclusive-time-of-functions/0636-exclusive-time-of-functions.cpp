class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<pair<pair<int, int>, int>> stack;
        for(int i = 0; i < logs.size(); ++i) {
            string log = logs[i];
            int idxFirstColon = -1, idxSecondColon = -1;
            for(int j = 0; j < log.size(); ++j) {
                if(log[j] == ':') {
                    if(idxFirstColon == -1) {
                        idxFirstColon = j;
                    } else {
                        idxSecondColon = j;
                    }
                }
            }
            int curId = stoi(log.substr(0, idxFirstColon));
            int curPos = stoi(log.substr(idxSecondColon + 1, log.size() - idxSecondColon - 1));
            bool isStart = log[idxFirstColon + 1] == 's';
            if(isStart) {
                stack.push({{curId, curPos}, 0});
            } else {
                auto top = stack.top();
                stack.pop();
                int prvId = top.first.first;
                int prvPos = top.first.second;
                int upperExSum = top.second;
                int exTime = (curPos - prvPos + 1) - upperExSum;
                ans[prvId] += exTime;
                if(stack.size() > 0) {
                    stack.top().second += exTime + upperExSum;
                }
            }
        }

        return ans;
    }
};