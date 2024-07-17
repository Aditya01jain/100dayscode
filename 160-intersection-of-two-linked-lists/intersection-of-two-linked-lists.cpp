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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> mp;
        ListNode* temp = headA;
        while(temp!=NULL){
            mp[temp]++;
            temp=temp->next;
        }
        ListNode* temp2 = headB;
        while(temp2!=NULL){
            mp[temp2]++;
            if(mp[temp2]==2){
                return temp2;
            }
            temp2=temp2->next;
        }
        return NULL;
    }
};