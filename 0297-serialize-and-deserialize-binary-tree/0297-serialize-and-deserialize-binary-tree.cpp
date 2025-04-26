/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void dfs(TreeNode* cur, string& encoded, bool isRoot) {
        if(!cur) {
            encoded += "x,";
            return;
        }
        encoded += to_string(cur->val) + ",";
        dfs(cur->left, encoded, false);
        dfs(cur->right, encoded, false);
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
        ++idx;
        if(encoded[idx] != 'x') {
            cur->left = buildTree(encoded, idx);
        } else {
            idx += 2;
        }
        if(encoded[idx] != 'x') {
            cur->right = buildTree(encoded, idx);
        } else {
            idx += 2;
        }
        return cur;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            return "";
        }
        string encoded = "";
        dfs(root, encoded, true);
        return encoded;
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