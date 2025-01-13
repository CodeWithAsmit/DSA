/* Approch 1 */

class Solution
{
  public:
  
    bool isPrime(int n)
    {
        if(n==1)
        {
            return 0;
        }
        
        int temp=sqrt(n);
        
        for(int i=2;i<=temp;i++)
        {
            if(n%i==0)
            {
                return 0;
            }
        }
        return 1;
    }
    
    int setBitCount(int n)
    {
        int count=0;
        while(n!=0)
        {
            if(n%2)
            {
                count++;
            }
            n=n/2;
        }
        return count;
    }
    
    int primeSetBits(int low, int high)
    {
        int ans=0;
        
        for(int i=low;i<=high;i++)
        {
            int temp = setBitCount(i);
            if(isPrime(temp))
            {
                ans++;
            }
        }
        return ans;
    }
};

/* Approach 2 */

class Solution
{
public:
    bool isprime(int n)
    {
        if (n<2)
        {
            return false;
        }
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    int primeSetBits(int L, int R)
    {
        int c=0;
        int dp[R+1];
        
        dp[0]=0;
        for(int i=1;i<=R;i++)
        {
            dp[i]=dp[i/2]+i%2;
        }
        
        for(int i=L;i<=R;i++)
        {
            if(isprime(dp[i]))
            {
                c++; 
            }
        }
        return c;
    }
};
