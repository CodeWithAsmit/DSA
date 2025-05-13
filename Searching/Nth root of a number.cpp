/* Time :- O(Nlogm) Space :- O(1) */

class Solution
{
  public:
    long long solve(int mid,int number,int target)
    {
        long long temp=1;
        while(number--)
        {
            temp = mid * temp;
            if(temp > target)
            {
                break;
            }
        }
        return temp;
    }
    int nthRoot(int n, int m)
    {
        int low = 1;
        int high= m;

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            long long product = solve(mid,n,m);
            
            if(product==m)
            {
                return mid;
            }
            else if(product > m)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return -1;  
    }
};
