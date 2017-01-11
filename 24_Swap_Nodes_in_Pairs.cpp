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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newhead = new ListNode(-1);
        ListNode* temp = newhead;
        newhead->next = head;
        while (head != NULL && head->next != NULL) {
            fun(temp, head, head->next);
            temp = temp->next->next;
            head = head->next;

        }
        return newhead->next;
    }
private:
    void fun(ListNode* p, ListNode* a, ListNode* b) {
        a->next = b->next;
        b->next = a;
        p->next = b;
    }
};