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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return fun(postorder, inorder, postorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* fun(vector<int>& postorder, vector<int>& inorder, int postindex, int low, int high) {
        if (low > high) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postindex]);
        int cur = 0;
        for (int i = low; i <= high; i++) {
            if (postorder[postindex] == inorder[i]) {
                cur = i;
                break;
            }
        }
        root->left = fun(postorder, inorder, postindex - ( high - cur + 1 ), low, cur - 1);
        root->right = fun(postorder, inorder, postindex - 1, cur + 1,high);
        return root;
    }
};