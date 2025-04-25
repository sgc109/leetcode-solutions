class Codec {
    string parsingKey = "";
    int keySize = 10;
public:
    Codec() {
        for(int i = 0; i < keySize; ++i) {
            parsingKey += (char)(random() % 256);
        }
    }

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret = "";
        for(int i = 0; i < strs.size(); ++i) {
            ret += strs[i];
            if(i < strs.size() - 1) {
                ret += parsingKey;
            }
        }
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ret;
        vector<int> parsingKeyStartIndices;
        int prevIdx = 0;
        while(1) {
            int idx = (int)s.find(parsingKey, prevIdx);
            if(idx == -1) {
                break;
            }
            parsingKeyStartIndices.push_back(idx);
            prevIdx = idx + keySize;
        }
        prevIdx = 0;
        for(int parsingKeyStartIdx : parsingKeyStartIndices) {
            string curStr = s.substr(prevIdx, parsingKeyStartIdx - prevIdx);
            ret.push_back(curStr);
            prevIdx = parsingKeyStartIdx + keySize;
        }
        ret.push_back(s.substr(prevIdx));
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));