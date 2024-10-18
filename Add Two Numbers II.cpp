// Approach 1: Reversing the LL's to start Addition from unit digit place
           //  Also reverse the array at the time of Returning
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
// ************** Use DummyNode ***********

// T.C. -> O(max(len1, len2)) + O(N)
// S.C. -> O(max(len1, len2))
class Solution {
public:
    ListNode* Reverse(ListNode* head){
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = Reverse(l1);
        ListNode* t2 = Reverse(l2);
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry =0;

        while(t1 != NULL || t2 != NULL){
            int sum = carry;
            if(t1) sum = sum + t1->val;
            if(t2) sum = sum + t2->val;

            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;

            curr->next = newNode;
            curr = curr->next;

            if(t1) t1= t1->next;
            if(t2) t2= t2->next;
        }
        if(carry > 0){
           ListNode* newNode = new ListNode(carry);
           curr->next = newNode; 
        }
        ListNode* head = Reverse(dummy->next);
        return head;
    }
};
