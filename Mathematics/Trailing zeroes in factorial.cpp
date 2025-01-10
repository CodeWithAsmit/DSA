/*Time :- log(n) with base 5 and Space :- O(1)*/

class Solution
{
  public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        int flag = 1;
        int fiveMultiple = 1;
        
        while(flag)
        {
            fiveMultiple = fiveMultiple * 5;
            if(n/fiveMultiple == 0)
            {
                flag = 0;
            }
            else
            {
                ans+=(n/fiveMultiple);
            }
        }
        return ans;
    }
};

/*Number of zero = number of power of 10 ie. number of power of 5*/
