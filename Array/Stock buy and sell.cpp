/* Time :- O(N) and Space :- O(1) */

class Solution
{
  public:
    int stockBuySell(vector<int> &arr)
    {
        int ans=0;
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i] > arr[i-1])
            {
                ans+=(arr[i]-arr[i-1]);
            }
        }
        return ans;
    }
};
