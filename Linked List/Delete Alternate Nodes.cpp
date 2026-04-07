/* Time :- O(N) Space :- O(1) */

class Solution
{
  public:
    void deleteAlt(struct Node *head)
    {
        while(head!=NULL && head->next!=NULL)
        {
            head->next = head->next->next;
            head = head ->next;
        }
    }
};
