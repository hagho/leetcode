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
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        int result = INT_MAX;
        for (int i = 1; i < tree.size(); i++)
            result = min(result, tree[i] - tree[i-1]);
        return result;
    }
    
private:
    vector<int> tree;
    void inOrder(TreeNode* root) {
        if (root->left != NULL) inOrder(root->left);
        tree.push_back(root->val);
        if (root->right != NULL) inOrder(root->right); 
    }
};