class Solution {
public:
    // n = 1, logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
    //                                                                            ^
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0); // [8]
        stack<int> stack; // []
        int prvTime; // 8
        for(auto& log : logs) {
            int funcId = stoi(log.substr(0, log.find(':'))); // 0
            int timestamp = stoi(log.substr(log.rfind(':') + 1)); // 7
            bool isStart = log.find('e') == -1;
            if(isStart) {
                if(!stack.empty()) {
                    ans[stack.top()] += timestamp - prvTime;
                }
                stack.push(funcId);
                prvTime = timestamp;
            } else {
                ans[stack.top()] += timestamp - prvTime + 1;
                stack.pop();
                prvTime = timestamp + 1;
            }
        }
        return ans;
    }
};