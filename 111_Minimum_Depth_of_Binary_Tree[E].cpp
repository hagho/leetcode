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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int res = INT_MAX;
        dfs(root, res, 1);
        return res;
    }
    void dfs(TreeNode* root, int &res, int depth) {
        if (root == NULL) {
            return ;
        }
        dfs(root->left, res, depth + 1);
        dfs(root->right, res, depth + 1);
        if (root->left == NULL && root->right == NULL) {
            res = min(depth, res);
        }
        
    }
};