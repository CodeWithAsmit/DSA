/* Time :- O(Nlogn) Space :- O(1) */

class Solution
{
public:
    int solve(int limit, vector<int>& piles)
    {
        int hoursRequired = 0;

        for(int i=0;i<piles.size();i++)
        {
            if(piles[i] > limit)
            {
                hoursRequired = hoursRequired + ceil(piles[i] / (double)limit);
            }
            else
            {
                hoursRequired++;
            }
        }
        return hoursRequired;
    }
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int low = 1;
        int high = INT_MAX;
        int ans = INT_MAX;

        while(low<=high)
        {
            int mid = low + (high - low) / 2;
            int hoursRequired = solve(mid,piles);

            if(hoursRequired>h)
            {
                low = mid + 1;
            }
            else
            {
                ans = min(ans,mid);
                high = mid -1;
            }
        }
        return ans;  
    }
};
