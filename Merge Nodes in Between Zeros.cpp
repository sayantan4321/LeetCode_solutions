// One Pass Solution

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
    ListNode* mergeNodes(ListNode* head) {
        ios::sync_with_stdio(false); 
        ListNode* temp = head->next; // Skip the first 0 node
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int total = 0;
        
        while (temp != nullptr) {
            if (temp->val == 0) {
                // Create a new node with the sum and add it to the result list
                ListNode* newNode = new ListNode(total);
                curr->next = newNode;
                curr = curr->next;
                // Reset the total for the next segment
                total = 0;
            } 
            else {
                // Add the value to the total sum
                total += temp->val;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};
