/* Time :- O(N*N) Space O(1) */

class Solution
{
  public:
  long long left(int l,int r,vector<long long int>& nums)
  {
       long long ans=1;
       for(int i=l;i<=r;i++)
       {
           ans=ans*nums[i];
       }
       return ans;
  }
  long long right(int l,int r,vector<long long int>& nums)
  {
       long long ans=1;
       for(int i=l;i<r;i++)
       {
           ans=ans*nums[i];
       }
       return ans;
  }
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n)
    {
        vector<long long int>v(n,0);
        for(int i=1;i<n;i++)
        {
            long long l=left(0,i-1,nums);
            long long r=right(i+1,n,nums);
            long long ans=l*r;
            v[i]=ans;
        }
        long long ans=1;
        for(int i=1;i<n;i++)
        {
            ans=ans*nums[i];
        }
        v[0]=ans;
        return v;
    }
}

/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int>left(nums.size(),1);
        vector<int>right(nums.size(),1);
        vector<int>ans;
        int n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back(left[i]*right[i]);
        }
        return ans;
    }
};

/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        long long prod = nums[0];
        vector<int>ans(n,1);

        ans[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            ans[i] = nums[i] * ans[i+1];
        }

        ans[0] = ans[1];
        for(int i=1;i<n-1;i++)
        {
            ans[i] = prod*ans[i+1];
            prod=prod*nums[i];
        }

        ans[n-1] = prod;
        return ans;
    }
};
