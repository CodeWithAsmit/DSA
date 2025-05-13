/* Time :- O(log N [Base 2] * log N [Base 5]) Space :- O(1) */

class Solution
{
    public:
    int solve(int number)
    {
        int ans = 0;
        int powFive = 5;
        int temp = 1;
        
        while(temp > 0)
        {
            temp = (number / powFive);
            ans = ans + temp;
            powFive = powFive * 5;
        }
        return ans;
    }
    
    int findNum(int n)
    {
        int low = 1;
        int high = INT_MAX;
        int ans = INT_MAX;
        
        while(low<=high)
        {
            int mid = high + (low-high) / 2;
            int zeroCount = solve(mid);
            
            if(zeroCount >= n)
            {
                ans = min(ans,mid);
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
