/*
Took: 20m 10s
Time: O(n)
Space: O(1)
*/


/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int cand = 0;
        for(int i = 1; i < n; ++i) {
            if(knows(cand, i)) {
                cand = i;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(i == cand) {
                continue;
            }
            if(knows(cand, i) || !knows(i, cand)) {
                return -1;
            }
        }
        return cand;
    }
};