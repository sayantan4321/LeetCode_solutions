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
    ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        } 
        return prev;
    }
    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* revHalf = reverseLL(slow);
        ListNode* curr = head;

        while(revHalf->next) {
            ListNode* tempFront = curr->next;
            curr->next = revHalf;
            
            ListNode* tempBack = revHalf->next;
            revHalf->next = tempFront;
            
            revHalf = tempBack;
            curr = tempFront;
        }
    }
};
