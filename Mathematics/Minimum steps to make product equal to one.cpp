// Time is O(N) and Space is O(1)

class Solution
{
  public:
    int makeProductOne(int arr[], int N)
    {
        int prod = 1;
        int stepsRequired = 0;
        int zeroCnt = 0;
        
        for(int i=0; i<N; i++)
        {
            if(arr[i] > 0)
            {
                stepsRequired+=(arr[i]-1);
                prod*=1;
            }
            else if(arr[i]<0)
            {
                stepsRequired+=(abs(arr[i])-1);
                prod*=-1;
            }
            else
            {
                zeroCnt++;
            }
        }
        
        if(prod<0 && zeroCnt==0)
        {
            return stepsRequired + 2;
        }
        return stepsRequired + zeroCnt;
    }
};
