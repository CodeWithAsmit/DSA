/* Time :- O(m+n) Space :- O[ min(n,m) --> worst case ] */

class Solution
{
public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_set<int> st;
        
        while(head2!=NULL)
        {
            st.insert(head2->data);
            head2 = head2->next;
        }
    
        Node* resultantList = new Node(-1);
        Node* tempMove = resultantList;
    
        while(head1!=NULL)
        {
            if(st.find(head1->data) != st.end())
            {
                tempMove->next = new Node(head1->data);
                tempMove = tempMove->next;
            }
            head1 = head1->next;
        }
    
        return resultantList->next;
    }
};