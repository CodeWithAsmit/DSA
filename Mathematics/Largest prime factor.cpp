/* Time Complexity :- n * sqrt(n) */

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
    
    int largestPrimeFactor(int n)
    {
        if(isPrime(n))
        {
            return n;
        }
        
        int temp = n/2;
        
        while(temp!=1)
        {
            if(n % temp==0 && isPrime(temp))
            {
                return temp;
            }
            else
            {
                temp--;
            }
        }
        return 2;
    }
};

/*Complexity :- sqrt(n)*/

class Solution
{
public: 
    long long int largestPrimeFactor(int N)
    {
        int ans=1;
        int m=N;
        for(int i=2;i*i<=m;i++)
        {
            while(N%i==0)
            {
                  ans=i;
                  N=N/i;
            }
              
        }
        ans=max(ans,N); 
        return ans;
    }
};
