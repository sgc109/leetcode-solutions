class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string file;
        while(getline(ss, file, '/')) {
            if(file == "..") {
                if(!stack.empty()) {
                    stack.pop_back();
                }
            } else if(file != "." && file != "") {
                stack.push_back(file);
            }
        }
        string ans = "";
        for(string str : stack) {
            ans += "/";
            ans += str;
        }
        return ans.empty() ? "/" : ans;
    }
};