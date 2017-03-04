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
        stack<int> s1, s2, s;
        while (l1 !=NULL) {
            s1.push(l1 -> val);
            l1 = l1 -> next; 
        }
        while (l2 !=NULL) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int carry = 0;
        while (!s1.empty() || !s2.empty()) {
            int tempsum = carry;
            if (!s1.empty()) {
                tempsum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                tempsum += s2.top();
                s2.pop();
            }
            carry = tempsum / 10 ;
            tempsum = tempsum % 10;
            s.push(tempsum);
        }
        if (carry == 1) {
            s.push(carry);
        }
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        while (!s.empty()) {
            temp -> next = new ListNode(s.top());
            s.pop();
            temp = temp -> next;
        }
        return result -> next;
    }
};