/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
/*
        //vector<ListNode*> pointers;
        int len = pointers.size();
        while (head != NULL) {
            pointers.push_back(head);
            head = head->next;
        }
        //cout << pointers.size()<< "fffffff";
        if ((len - n - 1) < 0) {
            if(pointers.size() == 1) {
                return (ListNode*)NULL;
            }
            return pointers[1];
        }
        if (len - n + 1 >= pointers.size()) {
            pointers[len - 2]->next =NULL;
            return pointers[0];
        }
        pointers[len - n - 1]->next = pointers[len - n + 1];
        return  pointers[0];
    }
*/ 
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;
        ListNode* pointer1 = newhead;
        ListNode* pointer2 = newhead;
        while (pointer1 != NULL) {
            pointer1 = pointer1->next;
            if (n-- < 0) {
                pointer2 = pointer2->next;
            }
        }
        pointer2->next = pointer2->next->next;
        return newhead->next;
    }
};

int main() {
    ListNode* test = new ListNode(1);
    ListNode* a = test;
    a->next = new ListNode(2);
    Solution S;
    // cout << "ffffff"
    ListNode* res = S.removeNthFromEnd(test, 2);
    while (res != NULL) {
        std::cout << res->val << " ";
        res = res->next;
    }
}
