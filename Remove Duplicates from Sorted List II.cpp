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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> mpp;
        ListNode* temp = head;
        while(temp != NULL){
            mpp[temp->val]++;
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = NULL;
        ListNode* curr = dummy;
        for(auto it : mpp){
            if(it.second == 1){
                ListNode* newNode = new ListNode(it.first);
                if(dummy->next == NULL){
                    dummy->next = newNode;
                    curr = newNode;
                }
                else{
                    curr->next = newNode;
                    curr = newNode;
                }
            }
        }
        return dummy->next;
    }
};
