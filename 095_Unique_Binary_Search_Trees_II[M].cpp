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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generatesubtrees(1, n);
    }
private:
    vector<TreeNode*> generatesubtrees(int s, int e) {
        vector<TreeNode*> res;
        if (s > e) {
            res.push_back(NULL);
            return res;
        }
        for (int i = s; i <= e; i++) {
            vector<TreeNode*> left = generatesubtrees(s, i - 1);
            vector<TreeNode*> right = generatesubtrees(i + 1, e);
            for (auto j = left.begin(); j != left.end(); j++) {
                for (auto k = right.begin(); k != right.end(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = *j;
                    root->right = *k;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};