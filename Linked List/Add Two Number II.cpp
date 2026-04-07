/* Time :- O(n1+n2) Space :- O(1) */

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

    ListNode* addBothList(ListNode* list1, ListNode* list2)
    {
        int sum = 0;
        int carry = 0;

        ListNode* result = new ListNode(-1);
        ListNode* answer = result;

        while (list1 || list2 || carry)
        {
            int total = carry;

            if (list1)
            {
                total = total + list1->val;
                list1 = list1->next;
            }

            if (list2)
            {
                total = total + list2->val;
                list2 = list2->next;
            }

            sum = total % 10;
            carry = total / 10;

            ListNode* temp = new ListNode(sum);
            result->next = temp;
            result = result->next;
        }
        return answer->next;
    }

    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2)
    {
        list1 = reverseList(list1);
        list2 = reverseList(list2);
        list1 = addBothList(list1, list2); 
        return reverseList(list1);   
    }
};

/* Time :- O(n1+n2) Space :- O(n1+n2) */

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2)
    {
        stack<int> s1, s2;

        while (list1)
        {
            s1.push(list1->val);
            list1 = list1->next;
        }

        while (list2)
        {
            s2.push(list2->val);
            list2 = list2->next;
        }

        int carry = 0;
        ListNode* result = NULL;

        while (!s1.empty() || !s2.empty() || carry)
        {
            int total = carry;

            if (!s1.empty())
            {
                total += s1.top();
                s1.pop();
            }

            if (!s2.empty())
            {
                total += s2.top();
                s2.pop();
            }

            ListNode* temp = new ListNode(total % 10);
            temp->next = result;
            result = temp;

            carry = total / 10;
        }

        return result;
    }
};

/* Time :- O(n1+n2) Space :- O(n1+n2) */

class Solution
{
public:
    int getLength(ListNode* head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* solve(ListNode* list1, ListNode* list2, int len1, int len2, int &carry)
    {
        if (!list1 && !list2)
        {
            return NULL;
        }

        int sum = 0;
        ListNode* nextNode = NULL;

        if (len1 > len2)
        {
            nextNode = solve(list1->next, list2, len1 - 1, len2, carry);
            sum = list1->val + carry;
        }
        else if (len2 > len1)
        {
            nextNode = solve(list1, list2->next, len1, len2 - 1, carry);
            sum = list2->val + carry;
        }
        else
        {
            nextNode = solve(list1->next, list2->next, len1 - 1, len2 - 1, carry);
            sum = list1->val + list2->val + carry;
        }

        ListNode* curr = new ListNode(sum % 10);
        curr->next = nextNode;
        carry = sum / 10;

        return curr;
    }

    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2)
    {
        int len1 = getLength(list1);
        int len2 = getLength(list2);
        int carry = 0;

        ListNode* result = solve(list1, list2, len1, len2, carry);

        if (carry)
        {
            ListNode* newHead = new ListNode(carry);
            newHead->next = result;
            return newHead;
        }
        return result;
    }
};