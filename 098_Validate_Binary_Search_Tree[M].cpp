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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        if (root->left == NULL) {
            return root->val < smallest(root->right) && isValidBST(root->right);
        }
        if (root->right == NULL) {
            return root->val > biggest(root->left) && isValidBST(root->left);
        }
        return root->val < smallest(root->right) && root->val > biggest(root->left) && isValidBST(root->right) && isValidBST(root->left);
    }
private:
    int smallest(TreeNode* root) {
        while (root->left) {
            root= root->left;
        }
        return root->val;
    }
    int biggest(TreeNode* root) {
        while (root->right) {
            root= root->right;
        }
        return root->val;
    }
};