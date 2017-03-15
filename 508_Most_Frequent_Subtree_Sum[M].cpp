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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> count;
        int maxcount = 0;
        vector<int> res;
        dfs(root, count, maxcount);
        for (const auto& a : count) {
            if (a.second == maxcount) {
                res.push_back(a.first);
            }
        }
        return res;

    }

private:
    int dfs(TreeNode* root, unordered_map<int, int>& count, int& maxcount) {
        if (root == NULL) {
            return 0;
        }
        if (root->right == NULL && root->left == NULL) {
            auto itor = count.find(root->val);
            if (itor == count.end()) {
                count[root->val] = 1;
            } else {
                count[root->val]++;
            }
            if (count[root->val] > maxcount) {
                maxcount = count[root->val];
            }
            return root->val;
        }
        int sum = root->val + dfs(root->left, count, maxcount) + dfs(root->right, count, maxcount);
        auto itor = count.find(sum);
        if (itor == count.end()) {
            count[sum] = 1;
        } else {
            count[sum]++;
        }
        if (count[sum] > maxcount) {
                maxcount = count[sum];
        }
        return sum;
    }
};