/* Time :- 3 * O(N) and Space :- 2 * O(N) */

class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
       int n=nums.size();
       vector<int>prefix(n,0);
       vector<int>suffix(n,0);
        
       prefix[0]=nums[0]; 
       for(int i=1;i<nums.size();i++)
       {
           prefix[i]=prefix[i-1]+nums[i];
       }
        
       suffix[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--)
       {
           suffix[i]=suffix[i+1]+nums[i];
       }
        
       for(int i=0;i<nums.size();i++)
       {
           if(prefix[i]==suffix[i])
           {
               return i;
           }
       }
       return -1;
    }
};

/* Time :- 2 * O(N) and Space :- O(1) */

class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
        int sum=0;
        int temp=0;

        for(auto x : nums)
        {
            sum=sum+x;
        }    

        for(int i=0;i<nums.size();i++)
        {
            sum=sum-nums[i];
            if(sum==temp)
            {
                return i;
            }
            else
            {
                temp=temp+nums[i];
            }
        }
        return-1;
    }
};
