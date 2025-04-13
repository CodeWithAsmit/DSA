/* Time :- O(N) Space :- O(1) */

class Solution
{
  public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        int i=0;
        int j=0;
        int sum = 0;
        
        vector<int>ans;
        
        while(j<arr.size())
        {
            sum = sum  + arr[j];
            
            if(sum == target)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(sum > target)
            {
                while(sum > target)
                {
                   sum = sum - arr[i];
                   i++;
                }
                if(sum == target)
                {
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    break;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                j++;
            }
        }
        
        if(ans.size() == 0)
        {
            ans.push_back(-1);
        }
        else
        {
            return ans;
        }
    }
};
