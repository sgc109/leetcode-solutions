class Solution {
    int getCurRevision(string& version, int& pos, int& prvIdx) {
        if(pos >= size(version)) {
            return 0;
        }
        int revision;
        while(pos < size(version) && version[pos] != '.') {
            ++pos;
        }
        
        if(prvIdx == pos) {
            revision = 0;
        } else {
            revision = stoi(version.substr(prvIdx + 1, pos));
            prvIdx = pos;
            ++pos;
        }

        return revision;
    }
public:
    int compareVersion(string version1, string version2) {
        int pos1 = 0, pos2 = 0;
        int prvIdx1 = -1, prvIdx2 = -1;

        while(pos1 < size(version1) || pos2 < size(version2)) {
            int revision1 = getCurRevision(version1, pos1, prvIdx1);
            int revision2 = getCurRevision(version2, pos2, prvIdx2);

            if(revision1 < revision2) {
                return -1;
            } else if(revision1 > revision2) {
                return 1;
            }
        }

        return 0;
    }
};