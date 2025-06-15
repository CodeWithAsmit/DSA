/* Time :- O(N*N) Space :- O(1) */

class Solution
{
    public:
    long long countTriplets(int n, long long sum, long long arr[])
    {
        int count=0;
        sort(arr,arr+n);
        
        for(int i=0;i<n;i++)
        {
            int low=i+1;
            int high=n-1;
		
            while(low<high)
            {
                if(arr[low] + arr[high] + arr[i] < (sum))
                {
                    count = count + (high - low);
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        return count;
    }
};
