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
    const unsigned char DUMMY = (unsigned char)((1<<8) - 1);
    void encode(TreeNode* cur, string& encoded) {
        if(cur == NULL) {
            encoded += DUMMY;
            encoded += DUMMY;
            return;
        }
        int lo = (cur->val) & ((1<<8)-1);
        int hi = (cur->val) >> 8;
        encoded += (char)hi;
        encoded += (char)lo;
        encode(cur->left, encoded);
        encode(cur->right, encoded);
    }
    
    TreeNode* decode(const char* encoded, int& pos) {
        int hi = (unsigned char)encoded[pos];
        int lo = (unsigned char)encoded[pos+1];
        pos += 2;
        if(hi == DUMMY && lo == DUMMY) {
            return NULL;
        }
        int num = (hi<<8) + lo;
        TreeNode* root = new TreeNode(num);
        root->left = decode(encoded, pos);
        root->right = decode(encoded, pos);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encoded = "";
        encode(root, encoded);
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return decode(data.c_str(), pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;