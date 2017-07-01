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
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, 0, sum);
    }
private:
    bool dfs(TreeNode* root, int tmp, int sum) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right ==NULL) {
             if (tmp + root->val == sum) {
                return true;
             } else {
                return false;
             }
        }
        return dfs(root->left, tmp + root->val, sum) || dfs(root->right, tmp + root->val, sum);

    }
};  