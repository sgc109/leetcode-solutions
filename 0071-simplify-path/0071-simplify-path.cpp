class Solution {
public:
 // path = "/.../a/../b/c/../d/./"
 //           ^
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> stack; // [..., b, d]
        string tmp;
        while(getline(ss, tmp, '/')) {
            if(tmp == "" || tmp == ".") {
                continue;
            } else if(tmp == "..") {
                if(!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(tmp);
            }
        }

        string ans = "/"; // /home/user/Prictures
        for(int i = 0; i < stack.size(); ++i) {
            ans += stack[i];
            if(i < stack.size() - 1) {
                ans += "/";
            }
        }
        return ans;
    }
};