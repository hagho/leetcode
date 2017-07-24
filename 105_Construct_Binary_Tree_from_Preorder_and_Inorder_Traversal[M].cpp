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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return fun(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* fun(vector<int>& preorder, vector<int>& inorder, int preindex, int low, int high) {
        if (low > high) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preindex]);
        int cur = 0;
        for (int i = low; i <= high; i++) {
            if (preorder[preindex] == inorder[i]) {
                cur = i;
                break;
            }
        }
        root->left = fun(preorder, inorder, preindex + 1, low, cur - 1);
        root->right = fun(preorder, inorder, preindex + cur - low + 1, cur + 1,high);
        return root;
    }
};