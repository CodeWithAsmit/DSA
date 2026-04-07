/* Time :- O(1) Space :- O(1) */

class Solution
{
  public:
    void deleteNode(Node* del_node)
    {
        Node* temp = del_node->next;
        
        del_node->data = temp->data;
        del_node->next = temp->next;
        
        delete temp;
    }
};