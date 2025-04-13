/* Time :- O(N) Space :- O(K) */

class Solution
{
  public:
    vector<int> firstNegInt(vector<int>& arr, int k)
    {
        int i=0;
        int j=0;
        
        queue<int>que;
        vector<int>ans;
        
        while(j<arr.size())
        {
            if(arr[j]<0)
            {
                que.push(arr[j]);
            }
            
            if(j-i+1 == k)
            {
                if(que.size())
                {
                    ans.push_back(que.front());
                }
                else
                {
                    ans.push_back(0);
                }
                
                if(!que.empty() && arr[i] == que.front())
                {
                    que.pop();
                }
                
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};
