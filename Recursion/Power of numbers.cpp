/* Time :- O(n) Space :- O(n) --> Brute Force Approach */

class Solution
{
  public:
    
    int solve(int p,int q)
    {
        if(q==0)
        {
            return 1;
        }
        return p*solve(p,q-1);
    }
    
    int reverseExponentiation(int n)
    {
        if (n==10)
        {
            return n;
        }
        return n*solve(n,n-1);
    }
};

/* Time :- O(logn) Space :- O(logn) --> Divide and Conquer Approach */

class Solution
{
public:
    int solve(int p, int q)
    {
        if (q == 0)
        {
            return 1;
        }
        
        int half = solve(p, q / 2);
        
        if (q % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return p * half * half;
        }
    }
    int reverseExponentiation(int n)
    {
        if (n == 10)
        {
            return n;
        }
        return solve(n, n);
    }
};
