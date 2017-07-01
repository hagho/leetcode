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
    int sumNumbers(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return 0;
        } 
        dfs(root, res, "");
        return accumulate(res.begin(), res.end(), 0);
    }

private:
    void dfs(TreeNode* root, vector<int>& res, string tmp) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            tmp += to_string(root->val);
            res.push_back(atoi(tmp.c_str()));
            return ;
        }
        dfs(root->left, res, tmp + to_string(root->val));
        dfs(root->right, res, tmp + to_string(root->val));

    }
};