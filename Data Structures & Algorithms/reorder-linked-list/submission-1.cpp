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

        // STEP 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // STEP 2: Separate second half
        ListNode* second = slow->next;
        slow->next = NULL;

        // STEP 3: Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = second;

        while (curr != NULL) {
            ListNode* temp = curr->next;

            curr->next = prev;

            prev = curr;
            curr = temp;
        }

        second = prev;

        // STEP 4: Merge two halves
        ListNode* first = head;

        while (second != NULL) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};