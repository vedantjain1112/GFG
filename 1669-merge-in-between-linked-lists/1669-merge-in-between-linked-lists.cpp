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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = nullptr;

  
        for (int i = 0; i < a - 1; ++i)
            ptr1 = ptr1->next;

       
        ListNode* temp = ptr1;

   
        for (int i = 0; i < b - a + 2; ++i)
            ptr1 = ptr1->next;


        ptr2 = ptr1;


        temp->next = list2;

 
        while (list2->next != nullptr)
            list2 = list2->next;

        list2->next = ptr2;

        return list1;
    }
};


void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}
