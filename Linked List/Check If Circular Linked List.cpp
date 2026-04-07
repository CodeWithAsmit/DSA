/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    bool isCircular(Node *head)
    {
        if (head == NULL)
        {
            return true;
        }
    
        Node* temp = head;
    
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                return false;
            }
            else if (temp->next == head)
            {
                return true;
            }
            else
            {
                temp = temp->next;
            }
        }
        return false;
    }
};
