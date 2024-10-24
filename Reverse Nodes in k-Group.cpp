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
    ListNode* findKth_Node(ListNode* temp, int k){
       if(temp == NULL) return NULL;
       k = k-1;
       while(temp != NULL){
           if(k==0) break;
           k--;
           temp = temp->next;
       } 
       return temp;
    }
    ListNode* reverse(ListNode* head){
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
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* temp = head;
       ListNode* prevNode = NULL;
       while(temp != NULL){
          ListNode* kth = findKth_Node(temp, k);
          if(kth == NULL){
            if(prevNode) prevNode->next = temp;
            break;
          }
          ListNode* nextNode = kth->next;
          kth->next = NULL;
          reverse(temp);

          if(temp == head){ // onlu for for first kth group
            head = kth; // to decide the head of the LL
          }
          else{
            prevNode->next = kth;
          }

          prevNode = temp;
          temp = nextNode;
       } 
       return head;
    }
};
