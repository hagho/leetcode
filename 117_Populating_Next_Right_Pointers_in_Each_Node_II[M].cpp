/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     void connect(TreeLinkNode *root) {
//         if (root == NULL) {
//             return;
//         }
//         queue<TreeLinkNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             TreeLinkNode* temp = q.front();
//             q.pop();
//             if (temp == NULL) {
//                 continue;
//             }
//             q.push(temp->left);
//             q.push(temp->right);
//         }
//         // dfs(root, NULL, false);
//         return ;
//     }
//     void dfs(TreeLinkNode *root, TreeLinkNode* father, bool flag) {
//         if (root == NULL) {
//             return;
//         }
//         if (father == NULL) {
//             root->next = NULL;
//         } else {
//             if (!flag && father->right != NULL) {
//                 root->next = father->right;
//             } else {
//                 root->next = fun(father->next);
//             }
//         }
//         // dfs(root->left, root, false);
//         // dfs(root->right, root, true);
//         return ;
//     }
//     TreeLinkNode* fun(TreeLinkNode* father) {
//         if (father == NULL) {
//             return NULL;
//         }
//         if (father->left != NULL) {
//             return father->left;
//         } 
//         if (father->right != NULL) {
//             return father->right;
//         }
//         return fun(father->next);
//     }
// };

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *now, *tail, *head;
        now = root;
        head = tail = NULL;
        while (now) {
            if (now->left) {
                if (tail != NULL) {
                    tail->next = now->left;
                    tail = now->left;
                } else {
                    head = now->left;
                    tail = now->left;
                }
            }
            if (now->right) {
                if (tail != NULL) {
                    tail->next = now->right;
                    tail = now->right;
                } else {
                    head = now->right;
                    tail = now->right;
                }
            }
            if (!(now = now->next)) {
                now = head;
                head = NULL;
                tail = NULL;
            }
        }
    }
};