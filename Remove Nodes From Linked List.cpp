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
--------- Approach - 1 ----------
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
       if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* nextNode = removeNodes(head->next);

        if (head->val < nextNode->val) {
            delete head;
            return nextNode;
        }

        head->next = nextNode;
        return head;
    }
};
----------- Approach - 2 ----------
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
       stack<ListNode*> st;
       ListNode* temp = head;

       while(temp != NULL){
        st.push(temp);
        temp = temp->next;
       }
       temp = st.top();
       st.pop();
       int maxNode = temp->val;

       ListNode* newHead = new ListNode(maxNode);
       while(!st.empty()){
         temp = st.top();
         st.pop();
         if(temp->val < maxNode){
            continue;
         }
         else{
            ListNode* newNode = new ListNode(temp->val);
            newNode->next = newHead;
            newHead = newNode;
            maxNode = temp->val;
         }
       }
       return newHead;
    }
};
