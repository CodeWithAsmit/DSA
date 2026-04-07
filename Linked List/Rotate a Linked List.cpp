/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head || !head->next || k == 0)
        {
            return head;
        }

        // Step 1: find length

        int countNode = 1;
        ListNode* temp = head;

        while (temp->next)
        {
            temp = temp->next;
            countNode++;
        }

        // Step 2: normalize k

        k = k % countNode;
        
        if (k == 0)
        {
            return head;
        }

        // Step 3: find (n-k)th node

        temp = head;

        for (int i = 1; i < countNode - k; i++)
        {
            temp = temp->next;
        }

        // Step 4: break
        
        ListNode* newHead = temp->next;
        temp->next = NULL;

        // Step 5: attach end to head

        ListNode* tail = newHead;
        while (tail->next)
        {
            tail = tail->next;
        }

        tail->next = head;
        return newHead;
    }
};