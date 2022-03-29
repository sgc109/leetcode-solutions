class Solution {
  struct Node {
    int sum;
    int i;
    int j;
    bool operator<(const Node& rhs) const {
      return sum > rhs.sum;
    }
  };
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int N = nums1.size();
    int M = nums2.size();
    vector<int> trimmedNums1{nums1.begin(), nums1.begin() + min(N, k)};
    vector<int> trimmedNums2{nums2.begin(), nums2.begin() + min(M, k)};
    vector<int> shortList = N < M ? trimmedNums1 : trimmedNums2;
    vector<int> longList = N < M ? trimmedNums2 : trimmedNums1;
    priority_queue<Node> pq;
    for(int i = 0; i < shortList.size(); ++i) {
      pq.push(Node{shortList[i] + longList[0], i, 0});
    }
    vector<vector<int>> ret;
    while(ret.size() < k && !pq.empty()) {
      Node cur = pq.top();
      pq.pop();
      int ansFirst = shortList[cur.i];
      int ansSecond = longList[cur.j];
      if(N >= M) swap(ansFirst, ansSecond);
      ret.push_back(vector<int>({ansFirst, ansSecond}));
      if(cur.j + 1 < longList.size()) {
        pq.push(Node{shortList[cur.i] + longList[cur.j + 1], cur.i, cur.j + 1});
      }
    }

    return ret;
  }
};
