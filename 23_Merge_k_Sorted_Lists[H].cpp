/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        ListNode* temp = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            temp = merge2Lists(temp, lists[i]);
        }
        return temp;
    }

private:
    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        while (a != NULL || b != NULL) {
            if (b == NULL || (a != NULL && a->val < b->val)) {
                temp->next = a;
                a = a->next;
            } else {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        return result->next;
    }
};