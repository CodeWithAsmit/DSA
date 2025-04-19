/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int i=0;
        int j=0;
        int sum = 0;
        int ans = INT_MAX;

        while(j < nums.size())
        {
            sum  = sum + nums[j];

            if(sum >= target)
            {    
                while(sum >= target)
                {
                    sum = sum - nums[i];
                    ans = min(ans,j-i+1);
                    i++;
                }
                j++;
            }
            else
            {
                j++;
            }
        }
        return ans == INT_MAX ? 0 : ans;    
    }
};
