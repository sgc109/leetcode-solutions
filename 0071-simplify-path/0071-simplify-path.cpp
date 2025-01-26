class Solution {
public:
    string simplifyPath(string path) {
        int pos = 0;

        vector<string> stk;
        while(pos < size(path)) {
            while(pos < size(path) && path[pos] == '/') {
                ++pos;
            }    
            if(pos == size(path)) {
                break;
            }
            int startIdx = pos;
            while(pos < size(path) && path[pos] != '/') {
                ++pos;
            }
            string file = path.substr(startIdx, pos - startIdx);
            if(file == "..") {
                if(stk.size() > 0) {
                    stk.pop_back();
                }
            } else if(file != ".") {
                stk.push_back(file);
            }
        }
        
        string ans = "";
        for(auto file : stk) {
            ans += "/";
            ans += file;
        }

        return ans == "" ? "/" : ans;
    }
};
