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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 1);
        bool flag = false;
        for (int i = 0; i < res.size(); i++) {
            if (!flag) {
                flag = !flag;
                continue;
            } else {
                flag = !flag;
                std::reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }
    void dfs(TreeNode* root, vector<vector<int>>& res, int depth) {
        if (root == NULL) {
            return ;
        }
        if (depth > res.size()) {
            res.push_back(vector<int>{root->val});
        } else {
            res[depth - 1].push_back(root->val);
        }

        dfs(root->left, res, depth + 1);
        dfs(root->right, res , depth + 1);
    }
};