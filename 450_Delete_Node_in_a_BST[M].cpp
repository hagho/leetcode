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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return root;
        }
        if (root->val == key) {
            if (root->right ==NULL) {
                TreeNode* left = root->left;
                delete root;
                return left;
            } else {
                TreeNode* right = root->right;
                while (right->left) {
                    right = right->left;
                }
                root->val ^= right->val;
                right->val ^= root->val;
                root->val ^= right->val;
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};