/* Time :- O((n+m) log(n+m))  Space :- O(n+m) */

class Solution
{
  public:
    Node* makeUnion(Node* head1, Node* head2)
    {
        set<int>st;
        Node* resultantList = new Node(-1);
        Node* curr = resultantList;
        
        while(head1!=NULL and head2!=NULL)
        {
            st.insert(head1->data);
            st.insert(head2->data);
            head1 = head1->next;
            head2 = head2->next;
        }
        
        while(head1!=NULL)
        {
            st.insert(head1->data);
            head1 = head1->next;
        }
        
        while(head2!=NULL)
        {
            st.insert(head2->data);
            head2 = head2->next;
        }
        
        for(int it : st)
        {
            Node* temp = new Node(it);
            curr->next = temp;
            curr = curr->next;
        }
        
        return resultantList->next;
    }
};

/* Time :- O(n+m + k log k)  Space :- O(n+m) */

class Solution
{
  public:
    Node* makeUnion(Node* head1, Node* head2)
    {
        unordered_set<int> st;
        Node* resultantList = new Node(-1);

        while(head1!=NULL)
        {
            st.insert(head1->data);
            head1 = head1->next;
        }

        while(head2!=NULL)
        {
            st.insert(head2->data);
            head2 = head2->next;
        }

        vector<int>vec(st.begin(), st.end());

        sort(vec.begin(), vec.end());
        
        Node* curr = resultantList;
    
        for(int it : vec)
        {
            curr->next = new Node(it);
            curr = curr->next;
        }
        return resultantList->next;
    }
};