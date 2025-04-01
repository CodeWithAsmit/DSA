/* Time :-  O(n+m) Space :- O(n+m) */

class Solution
{
  public:
    int findUnion(vector<int>& a, vector<int>& b)
    {
        unordered_set<int>st;
        
        for(auto it : a)
        {
            st.insert(it);
        }
        for(auto it : b)
        {
            st.insert(it);
        }
        
        return st.size();
    }
};
