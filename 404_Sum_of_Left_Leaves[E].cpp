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
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, 1);
    }
private:
    int dfs(TreeNode* root, int position) {
        int res = 0; 
        if (root ==  NULL) {
            return res;
        } 
        if (root->right ==NULL && root->left == NULL && position == 0) {
            return root->val;
        }
        else {
            res = dfs(root->left, 0) + dfs(root->right , 1);
        }
        return res;
    }

};