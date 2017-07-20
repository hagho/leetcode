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
    ListNode* partition(ListNode* head, int x) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* first = new_head;
        ListNode* second = head;
        while (second && second->next) {
            while (first->next && first->next->val < x) {
                first = first->next;
                second = first->next;
            }
            while (second && second->next && second->next->val >= x) {
                second = second->next;
            }
            if (first->next && second->next) {
                ListNode* temp = first->next;
                first->next = second->next;
                second->next = second->next->next;
                first->next->next = temp;
            }
        }
        return new_head->next;
    }
};