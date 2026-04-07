/* Approach 1 :- Recursive O(N) --> Time and O(N) --> Recursive Space */

class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        if(head==NULL||head->next==NULL)
        {
            return head;  /*always return head of reversed linked list*/
        }
        
        struct Node* newHead = reverseList(head->next);  /*newHead Will Remain Contant ie. always point to end of list*/
        
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
};

/* Approach 2 :- Iterative O(N) --> Time and O(1) --> Constant Space */

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        if(head == NULL || head->next == NULL)
        {
            return head;
        }   

        while(curr!=NULL)
        {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};