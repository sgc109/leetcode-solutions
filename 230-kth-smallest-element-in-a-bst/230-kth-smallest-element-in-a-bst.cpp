class Solution {
int ans = -1;
int find(TreeNode* node, int k) {
  if (node == nullptr) {
    return 0;
  }
  int left = find(node->left, k);
  if (ans != -1) {
    return 0;
  }
  if (k - left == 1) {
    ans = node->val;
    return 0;
  }
  int right = find(node->right, k - left - 1);
  return 1 + left + right;
}
public:
  int kthSmallest(TreeNode* root, int k) {
    find(root, k);
    return ans;
  }
};
