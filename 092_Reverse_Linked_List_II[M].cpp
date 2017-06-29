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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* res = head;
        for (int i = 1; i < m; i++) {
            head = head->next;
            temp = temp->next;
        }

        
        ListNode* q = head->next;
        ListNode* p = head;
        head->next = NULL;
        ListNode* r = NULL;
        for (int i = m; i < n; i++) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        head->next = q;
        temp->next = p;
        if (m == 1) return temp->next; 
        else return res;
    }
};