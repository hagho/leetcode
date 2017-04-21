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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur) {
            if (cur->left) {
                pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }
                if (pre->right) {
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                } else {
                    pre->right = cur;
                    cur = cur->left;
                }
            } else {
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
