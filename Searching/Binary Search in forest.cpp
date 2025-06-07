/* Time :- O(nlogn) Space :- O(1) */

class Solution
{
    public:
    int findMaximum(int n,int tree[])
    {
        int maxValue = INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxValue = max(maxValue,tree[i]);
        }
        return maxValue;
    }

    int solve(int height, int n, int tree[])
    {
        int woodCollect = 0;
        
        for(int i=0;i<n;i++)
        {
            if(tree[i] > height)
            {
                woodCollect = woodCollect + (tree[i] - height);
            }
        }
        return woodCollect;
    }
    
    int find_height(int tree[], int n, int k)
    {
        int low = 0;
        int high = findMaximum(n,tree);
        int ans = -1;
        
        while(low<=high)
        {
            int mid = low + (high - low) / 2;
            int woodGet = solve(mid,n,tree);
            
            if(woodGet == k)
            {
                ans = mid;
                break;
            }
            else if(woodGet > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
