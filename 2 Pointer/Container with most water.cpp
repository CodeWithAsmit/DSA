/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int low = 0;
        int high = height.size()-1;
        int ans = INT_MIN;

        while(low<high)
        {
            int waterCollected = (high-low) * min(height[low],height[high]);
            ans = max(ans,waterCollected);

            if(height[low] > height[high])
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        return ans;
    }
};
