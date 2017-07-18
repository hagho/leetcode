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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(root, sum, temp, res);
        return res;
    }
    void dfs(TreeNode* root, int sum, vector<int>& temp, vector<vector<int>>& res) {
        if (root == NULL) {
            return ;
        }
        if (root->left == NULL && root->right == NULL && sum == root->val) {
            temp.push_back(root->val);
            res.push_back(temp);   
            temp.pop_back();
            return ;
        }
        temp.push_back(root->val);
        dfs(root->left, sum - root->val, temp, res);
        dfs(root->right, sum - root->val, temp, res);
        temp.pop_back();
        return ;
    }
};