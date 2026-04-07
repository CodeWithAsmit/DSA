/* Time :- O(N) Space :- O(1) */

class Solution
{
  public:
    Node* removeDuplicates(Node* head)
    {
        Node* moveList = head;
        
        while(moveList->next!=NULL)
        {
            if(moveList->data == moveList->next->data)
            {
                moveList->next=moveList->next->next;
            }
            else
            {
                moveList = moveList->next;
            }
        }
        return head;
    }
};
