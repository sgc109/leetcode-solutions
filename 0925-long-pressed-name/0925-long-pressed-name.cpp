class Solution {
    struct Occur {
        char ch;
        int frq;
    };

    vector<Occur> merge(string str) {
        vector<Occur> ret;

        char lastCh = 0;
        int frq = 0;
        for(char c : str) {
            if(lastCh == 0) {
                lastCh = c;
                frq = 1;
            } else if (lastCh == c){
                frq++;
            } else {
                ret.push_back(Occur{lastCh, frq});
                lastCh = c;
                frq = 1;
            }
        }
        ret.push_back(Occur{lastCh, frq});
        return ret;
    }
public:
    bool isLongPressedName(string target, string typed) {
        vector<Occur> targetOcc = merge(target);
        vector<Occur> typedOcc = merge(typed);

        if(targetOcc.size() != typedOcc.size()) {
            return false;
        }

        for(int i = 0; i < targetOcc.size(); ++i) {
            if(targetOcc[i].ch != typedOcc[i].ch) {
                return false;
            }
            if(targetOcc[i].frq > typedOcc[i].frq) {
                return false;
            }
        }
        return true;
    }
};