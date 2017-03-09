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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = root->val;
        while (!q.empty()) {
            res = q.front()->val;
            vector<TreeNode*> temp;
            while (!q.empty()) {
                temp.push_back(q.front());
                q.pop();
            }
            for (int i = 0; i < temp.size(); i++) {
                if(temp[i]->left != NULL) {
                    q.push(temp[i]->left);
                }
                if (temp[i]->right != NULL) {
                    q.push(temp[i]->right);
                }
            }
        }
        return res;
    }
};