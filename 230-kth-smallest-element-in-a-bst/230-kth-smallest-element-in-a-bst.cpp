class Solution {
int ans = -1;
void find(TreeNode* node, int& k) {
  if (node == nullptr) {
    return;
  }
  find(node->left, k);
  if (ans != -1) {
    return;
  }
  if (k == 1) {
    ans = node->val;
    return;
  }
  --k;
  find(node->right, k);
}
public:
  int kthSmallest(TreeNode* root, int k) {
    find(root, k);
    return ans;
  }
};
