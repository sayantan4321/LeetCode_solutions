/*
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* leftprev = dummy;
        ListNode* temp = head;
        
        for(int i=0; i<left-1; i++){
            leftprev = leftprev->next;
            temp = temp->next;
        }
        ListNode* prev = NULL;
        ListNode* newHead = temp;

        for(int i=0; i<=right-left; i++){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        leftprev->next = prev;
        newHead->next = temp;

        return dummy->next;

    }
};
