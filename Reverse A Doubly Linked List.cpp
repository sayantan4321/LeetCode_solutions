-------- Approach -1 -----------
    USING STACK 

--------- Approach -2 ----------
T.C. - O(N)
S.C. - O(1)    
class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

Node* reverseDLL(Node* head)
{   
    // Write your code here   
    if(head == NULL || head->next == NULL) return head;
    Node* curr = head;
    Node* last = NULL;

    while(curr != NULL){
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;

        curr = curr->prev;
    }
    return last->prev;

}
