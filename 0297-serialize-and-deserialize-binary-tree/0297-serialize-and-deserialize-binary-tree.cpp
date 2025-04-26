/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

 1l2ur3l4ur5uu
 */
class Codec {
    void encode(TreeNode* cur, string& encoded) {
        encoded += to_string(cur->val);
        if(cur->left) {
            encoded += 'l';
            encode(cur->left, encoded);
        }
        if(cur->right) {
            encoded += 'r';
            encode(cur->right, encoded);
        }
        encoded += 'u';
    }

    TreeNode* buildTree(string& encoded, int& idx) {
        int num = 0;
        bool isNegative = false;
        if(encoded[idx] == '-') {
            isNegative = true;
            ++idx;
        }
        while(isdigit(encoded[idx])) {
            num = num * 10 + encoded[idx] - '0';
            ++idx;
        }
        TreeNode* cur = new TreeNode(isNegative ? -num : num);
        if(encoded[idx] == 'l') {
            ++idx;
            cur->left = buildTree(encoded, idx);
        }
        if(encoded[idx] == 'r') {
            ++idx;
            cur->right = buildTree(encoded, idx);
        }

        ++idx;
        return cur;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            return "";
        }
        string ret = "";
        encode(root, ret);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) {
            return nullptr;
        }
        int idx = 0;
        return buildTree(data, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));