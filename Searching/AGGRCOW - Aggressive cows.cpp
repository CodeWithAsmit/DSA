/* Time :- O(Nlogn) Space :- O(1) */

/* Same question on leetcode --> 1552 */

class Solution
{
public:
    bool solve(int distance, vector<int>& stalls, int cows)
    {
        int keptCows = 1;
        int lastKeptPosition = stalls[0];

        for(int i=1;i<stalls.size();i++)
        {
            if(abs(stalls[i] - lastKeptPosition) >= distance)
            {
                keptCows++;
                lastKeptPosition = stalls[i];
            }
        }
        return keptCows >= cows;
    }
    int maxDistance(vector<int>& stalls, int cows)
    {
        sort(stalls.begin(),stalls.end());

        int low = 1;
        int high = stalls[stalls.size()-1] - stalls[0];
        int requiredDistance = INT_MIN;

        while(low<=high)
        {
            int mid = low + (high - low) / 2;

            if(solve(mid, stalls, cows))
            {
                requiredDistance = max(requiredDistance,mid);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return requiredDistance;
    }
};
