/* Time :- O(Nlogn) Space :- O(1) */

class Solution
{
public:
    int solve(int day,vector<int>& bloomDay, int k)
    {
        int flowerCount = 0;
        int bouquetCount = 0;

        for(int i=0;i<bloomDay.size();i++)
        {
            if(day >= bloomDay[i])
            {
                flowerCount++;
            }
            else
            {
                flowerCount = 0;
            }

            if(flowerCount==k)
            {
                bouquetCount++;
                flowerCount = 0;
            }
        }
        return bouquetCount;
    }
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        int ans = INT_MAX;
        int bouquetCount = 0;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low<=high)
        {
            int mid = low + (high - low) / 2;
            int bouquetCount = solve(mid,bloomDay,k);

            if(bouquetCount>=m)
            {
                ans = min(ans,mid);
                high = mid-1;
            }
            else
            {
                low = mid +1;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
