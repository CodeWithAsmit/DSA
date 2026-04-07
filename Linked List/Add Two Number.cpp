/* Approach 1 Time Complexity :- O[ min(length_of_l1, length_of_l2) ] , Space Complexity:- O[ max(length_of_l1, length_of_l2) + 1 ] */

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2)
    {
        int sum=0;
        int carry=0;
        ListNode* result = new ListNode(-1);
        ListNode* answer = result;

        while(list1 != NULL and list2 != NULL)
        {
            int total = list1->val + list2->val + carry;
            sum = total % 10;
            carry = total / 10;
            ListNode* temp = new ListNode(sum); 
            result->next = temp;
            list1 = list1->next;
            list2 = list2->next;
            result = result->next;
        }

        while(list1 != NULL)
        {
            int total = list1->val + carry;
            sum = total % 10;
            carry = total / 10;
            ListNode* temp = new ListNode(sum); 
            result->next = temp;
            list1 = list1->next;
            result = result->next;
        }   

        while(list2 != NULL)
        {
            int total = list2->val + carry;
            sum = total % 10;
            carry = total / 10;
            ListNode* temp = new ListNode(sum); 
            result->next = temp;
            list2 = list2->next;
            result = result->next;
        }

        if(carry)
        {
            ListNode* temp = new ListNode(carry);
            result->next = temp;
        }

        return answer->next;
    }
};


/* Approach 2 - Optimal Code */

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2)
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
};