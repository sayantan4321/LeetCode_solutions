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
---------- APPROACH - 1 ------------
    // BRUTE 
 TC -> O(Len) + O(len-n)
 SC -> 0(1)   
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* temp = head;
       for(int i=1; i<=n; i++){
          temp = temp->next;
       }
       if(temp == NULL){
        ListNode* res = head->next;
        delete(head);
        return res;
       }
       ListNode* prev = head;
       while(temp != NULL && temp->next != NULL){
        prev = prev->next;
        temp = temp->next;
       }
       ListNode* Del = prev->next;
       prev->next = prev->next->next;
       delete(Del);
       
       return head;
    }
};

----------- APPROACH - 2 -----------
    // OPTIMAL
TC -> O(Len/2) + O(len/2) -> O(N)
SC -> 0(1)  
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int K) {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0; i<K;  i++){
            fast = fast->next;
        }
        if(fast == NULL) return head->next;
        
        while(fast->next != NULL) { // after k position fast will start
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete(delNode);
    
        return head;
    } 
