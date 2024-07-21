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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        
        // Calculate the length of the list
        ListNode* temp = head;
        int l = 0;
        while (temp != nullptr) {
            temp = temp->next;
            l++;
        }

        // If the head needs to be removed
        if (n == l) {
            ListNode* newHead = head->next;
            delete head; // Free the memory of the old head
            return newHead;
        }

        // Find the (l-n)th node
        int c = l - n - 1;
        ListNode* temp1 = head;
        while (c-- > 0 && temp1 != nullptr) {
            temp1 = temp1->next;
        }

        // Remove the nth node from the end
        if (temp1 != nullptr && temp1->next != nullptr) {
            ListNode* nodeToDelete = temp1->next;
            temp1->next = temp1->next->next;
            delete nodeToDelete; // Free the memory of the removed node
        }

        return head;
    }
};
