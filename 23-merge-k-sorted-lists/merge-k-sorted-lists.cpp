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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using NodeEntry = pair<int, pair<int, ListNode*>>;
        priority_queue<NodeEntry, vector<NodeEntry>, greater<NodeEntry>> q;
        
        // Initialize the priority queue with the first node of each list
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                q.push(make_pair(lists[i]->val, make_pair(i, lists[i])));
            }
        }
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        while (!q.empty()) {
            NodeEntry temp = q.top();
            q.pop();

            int val = temp.first;
            int listIndex = temp.second.first;
            ListNode* node = temp.second.second;
            current->next = node;
            current = current->next;
            if (node->next != nullptr) {
                q.push(make_pair(node->next->val, make_pair(listIndex, node->next)));
            }
        }
        ListNode* mergedHead = dummyHead->next;
        delete dummyHead; 
        return mergedHead;
    }
};