/* Time :- O(N) Space :- O(1) */

class Solution
{
public:

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL)
        {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* findMidElement(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != NULL)
        {
            slow = slow->next;
        }
        return slow;
    }

    bool checkPalindrome(ListNode* head, ListNode* secondHalf)
    {
        while (secondHalf != NULL)
        {
            if (head->val != secondHalf->val)
            {
                return false;
            }
            head = head->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        ListNode* secondHalf = findMidElement(head);
        secondHalf = reverse(secondHalf);
        return checkPalindrome(head, secondHalf);
    }
};