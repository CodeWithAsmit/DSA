#Time and Space complexity O(1)

class Solution
{
  public:
    int countSquares(int N)
    {
        int temp=sqrt(N);
        if((temp*temp)==N)
        {
            return temp-1;   
        }
        else
        {
            return temp;
        }
    }
};

#Time complexity is log(n) and Space complexity is O(1)

class Solution
{
  public:
    int countSquares(int n)
    {
        if (n==1)
        {
            return 0;
        }
        
        long low = 1;
        long high = n;
        long mid = 0;
        
        while (low <= high)
        {
            mid = low + ((high - low) / 2);
            long temp = mid * mid;
            
            if (temp == n)
            {
                return mid-1;  
            }
            else if (temp > n)
            {
                high = mid - 1;  
            }
            else
            {
                low = mid + 1;
            }
        }
        return (int)high;
    }
};
