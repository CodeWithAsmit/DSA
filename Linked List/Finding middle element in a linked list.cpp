/* Approach 1 Time :- O(N) Space :- (1) [ Not in one pass ] */

class Solution
{
public:
    int getMiddle(Node *head)
    {
        Node* temp=head;
        int size=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            size++;
        }
        if(size%2!=0)
        {
            size=(size+1)/2;
        }
        else
        {
            size=(size+2)/2;
        }
        temp=head;
        while(--size)
        {
            temp=temp->next;
        }
        return temp->data;
    }
};

/* Approach 2 Time :- O(N) Space :- O(1) */

class Solution
{
  public:
    int getMiddle(Node* head)
    {
        Node* slow = head;
        Node* fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};