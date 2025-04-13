/* Time :- O(N) Space :- O(1) */

class Solution
{
  public:
    int maximumSumSubarray(vector<int>& arr, int k)
    {
        int i=0;
        int j=0;
        int sum = 0;
        int ans = INT_MIN;
        
        while(j<arr.size())
        {
            sum = sum  + arr[j];
            
            if(j-i+1 == k)
            {
                ans = max(ans,sum);
                sum = sum - arr[i];
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
