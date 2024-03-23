/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

     
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

       
        ListNode *firstHalf = head;
        ListNode *secondHalf = slow->next;
        slow->next = nullptr;


        ListNode *prev = nullptr;
        ListNode *current = secondHalf;
        ListNode *nextNode;

        while (current) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        secondHalf = prev;

     
        ListNode *p1 = firstHalf;
        ListNode *p2 = secondHalf;

        while (p1 && p2) {
            ListNode *temp1 = p1->next;
            ListNode *temp2 = p2->next;

            p1->next = p2;
            p2->next = temp1;

            p1 = temp1;
            p2 = temp2;
        }
    }
};


void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}