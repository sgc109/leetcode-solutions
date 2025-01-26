/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> ans;
    int K;
    TreeNode* targetNode;

    int searchTarget(TreeNode* curNode) {
        if(curNode == NULL) {
            return -1;
        }

        if(curNode == targetNode) {
            return 1;
        }

        int leftDistToTarget = searchTarget(curNode->left);
        int rightDistToTarget = searchTarget(curNode->right);
        if(leftDistToTarget == -1 && rightDistToTarget == -1) {
            return -1;
        }

        int distToTarget = max(leftDistToTarget, rightDistToTarget);
        if(distToTarget == K) {
            ans.push_back(curNode->val);
            return distToTarget + 1; 
        }

        if(leftDistToTarget != -1) {
            searchAnswer(curNode->right, 0, K - leftDistToTarget - 1);
        } else {
            searchAnswer(curNode->left, 0, K - rightDistToTarget - 1);
        }

        return distToTarget + 1;
    }

    void searchAnswer(TreeNode* curNode, int curDist, int targetDist) {
        if(curNode == NULL) {
            return;
        }
        if(curDist == targetDist) {
            ans.push_back(curNode->val);
            return;
        }
        searchAnswer(curNode->left, curDist + 1, targetDist);
        searchAnswer(curNode->right, curDist + 1, targetDist);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == target) {
            searchAnswer(target, 0, k);
            return ans;
        }

        this->K = k;
        this->targetNode = target;
        
        searchTarget(root);
        searchAnswer(target, 0, k);

        return ans;
    }
};