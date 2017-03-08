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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != NULL) {
            q.push(root);
        }
        vector<int> res;
        while(!q.empty()) {
            int t = q.front()->val;
            vector<TreeNode*> temp;
            while (!q.empty()) {
                temp.push_back(q.front());
                if (t < q.front()->val) {
                    t = q.front()->val;
                }
                q.pop();
            } 
            res.push_back(t);
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i]->left != NULL) {
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


