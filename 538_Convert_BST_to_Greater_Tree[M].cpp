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
    TreeNode* convertBST(TreeNode* root) {
        fun(root);
        return root;
    }
private:
    int cursum = 0;
    void fun(TreeNode* root) {
        if (!root) {
            return ;
        }
        if (root->right) {
            fun(root->right);
        }
        cursum += root->val;
        root->val = cursum;
        if (root->left) {
            fun(root->left);
        }
    }
};