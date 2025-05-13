/* Time :- O(logn) Space :- O(1) */

class Solution
{
public:
    int mySqrt(int x)
    {
        if(x==0)
        {   
            return 0;
        }
        if(x<=3)
        {
            return 1;
        }

        long long int low = 1;
        long long int high= x/2;

        while(low<=high)
        {
            long long int mid = high + (low-high)/2;

            if(mid*mid==x)
            {
                return mid;
            }
            else if(mid*mid > x)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return high;    
    }
};
