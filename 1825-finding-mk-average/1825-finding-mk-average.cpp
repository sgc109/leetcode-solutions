/*
Took: over 1 hour
Time: O(MlogM + (N - M) * (KlogK + (M - K)log(M - K)))
Space: O(M)
*/

class MKAverage {
    vector<multiset<int>> bsts;
    vector<int> sums;
    vector<int> nums;
    queue<int> Q;
    int M, K;
    int getMax(multiset<int>& bst) { return *bst.rbegin(); }

    int getMin(multiset<int>& bst) { return *bst.begin(); }

public:
    MKAverage(int m, int k) {
        M = m;
        K = k;
        sums = vector<int>(3, 0);
        nums = vector<int>();
        Q = queue<int>();
        bsts = vector<multiset<int>>(3);
    }

    void addElement(int num) {
        if (size(Q) < M) {
            nums.push_back(num);
        }

        Q.push(num);
        if (size(Q) == M) {
            sort(begin(nums), end(nums));
            vector<pair<int, int>> ranges = {{0, K}, {K, M - K}, {M - K, M}};
            for (int i = 0; i < size(ranges); ++i) {
                auto range = ranges[i];
                for (int j = range.first; j < range.second; ++j) {
                    bsts[i].insert(nums[j]);
                    sums[i] += nums[j];
                }
            }
        } else if (size(Q) == M + 1) {
            int toAdd = num;
            int addIdx;
            if (toAdd <= getMax(bsts[0])) {
                addIdx = 0;
            } else if (toAdd <= getMax(bsts[1])) {
                addIdx = 1;
            } else {
                addIdx = 2;
            }
            sums[addIdx] += toAdd;
            bsts[addIdx].insert(toAdd);

            int removeIdx;
            int toRemove = Q.front();
            Q.pop();

            if (toRemove <= getMax(bsts[0])) {
                removeIdx = 0;
            } else if (toRemove <= getMax(bsts[1])) {
                removeIdx = 1;
            } else {
                removeIdx = 2;
            }
            sums[removeIdx] -= toRemove;
            bsts[removeIdx].erase(bsts[removeIdx].find(toRemove));

            for (int i = addIdx; i != removeIdx;
                 i += (removeIdx - addIdx >= 0 ? 1 : -1)) {
                int nextIdx = (addIdx < removeIdx ? i + 1 : i - 1);
                int toMoveNum =
                    (addIdx < removeIdx ? getMax(bsts[i]) : getMin(bsts[i]));
                bsts[i].erase(bsts[i].find(toMoveNum));
                sums[i] -= toMoveNum;
                bsts[nextIdx].insert(toMoveNum);
                sums[nextIdx] += toMoveNum;
            }
        }
    }

    int calculateMKAverage() {
        if (size(Q) < M) {
            return -1;
        }
        return sums[1] / (M - 2 * K);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */