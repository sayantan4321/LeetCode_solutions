------------ Appraoch -1 --------------
  //  starting from the mentioned node and skip the node->next to node->next->next
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
    void deleteNode(ListNode* node) {
      //change the current node's value to next node's value
       node->val = node->next->val;
       node->next = node->next->next;
    }
};
