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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int jinwei = 0;
        ListNode* result = new ListNode((l1->val + l2->val + jinwei) % 10);
        ListNode* res = result;

        jinwei = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != NULL && l2 != NULL) {
            result->next = new ListNode((l1->val + l2->val + jinwei) % 10);
            result = result->next;
            jinwei = (l1->val + l2->val + jinwei) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == NULL && l2 == NULL) {
            if (jinwei == 1) {
                 result->next = new ListNode(jinwei);
            }
            return res;
        }
        while (l2 != NULL) {
            result->next = new ListNode((l2->val + jinwei) % 10);
            jinwei = (l2->val + jinwei) / 10;  
            result = result->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            result->next = new ListNode((l1->val + jinwei) % 10);
            jinwei = (l1->val + jinwei) / 10;  
            result = result->next;
            l1 = l1->next;
        }
        if (jinwei == 1) {
                 result->next = new ListNode(jinwei);
        }
        return res;
    }
};