/*
   0    0 00
0             0
    0   0 11
 0           0
 
 len(logs) <= 500
 id < 100
 timestamp <= 10^9

       1,2    1,5
  0,0             0,6
 
*/
class Solution {
public:
// n = 1, logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        // {{func_id, timestamp}, subtractor}
        vector<int> ans(n, 0); // [8]
        stack<pair<pair<int,int>,int>> stack; // []
        for(auto& log : logs) {
            int funcId = stoi(log.substr(0, log.find(':')));
            bool isStart = log.find('e') == -1;
            int timestamp = stoi(log.substr(log.rfind(':') + 1));
            if(isStart) {
                stack.push({{funcId, timestamp}, 0});
            } else {
                auto top = stack.top(); // ((0,0),5)
                stack.pop();
                int gap = timestamp - top.first.second + 1;  // 7 - 0 + 1 = 3
                int exTime = gap - top.second; // 8 - 5 = 3
                ans[funcId] += exTime;
                if(!stack.empty()) {
                    stack.top().second += gap;
                }
            }
        }
        return ans;
    }
};