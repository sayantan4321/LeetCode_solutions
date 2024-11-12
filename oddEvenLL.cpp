--------- APPROACH - 1 ---------
    // BRUTE FORCE
TC -> O(2N)
SC -> O(N)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        vector<int> arr;
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
           arr.push_back(temp->val);
           temp = temp->next;
        }
        if(temp != NULL) arr.push_back(temp->val);

        temp = head->next;
        while(temp != NULL && temp->next != NULL){
           arr.push_back(temp->val);
           temp = temp->next;
        }
        if(temp != NULL) arr.push_back(temp->val);
        
        int i=0;
        ListNode* cur = head;
        while(cur != NULL){
            cur->val = arr[i];
            i++;
            cur = cur->next;
        }
        return head;
    }
};
--------- APPROACH - 2 ------------
    // OPTIMAL
TC -> O(N)
SC -> O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = head->next;

        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};
