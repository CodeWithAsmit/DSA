/* Approach 1 */

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int numsLength = nums.size();
        vector<int>preProd(numsLength,0);
        vector<int>postProd(numsLength,0);
        int ans = INT_MIN;

        preProd[0] = nums[0];

        for(int i=1;i<nums.size();i++)
        {
            if(preProd[i-1]==0)
            {
                preProd[i]=nums[i];
            }
            else
            {
                preProd[i] = preProd[i-1] * nums[i];
            }
        }

        postProd[numsLength-1] = nums[numsLength-1];
        
        for(int i=numsLength-2;i>=0;i--)
        {
            if(postProd[i+1]==0)
            {
                postProd[i] = nums[i];
            }
            else
            {
                postProd[i] = postProd[i+1] * nums[i];
            }
        }

        for(int i=0;i<nums.size();i++)
        {
           ans = max(ans,max(preProd[i],postProd[i]));
        }

        return ans;
    }
};

/* Approach 2 */

class Solution
{
public:
    int maxProduct(vector<int>&nums)
    {
        int ans=nums[0];
        int mx=ans;
        int mn=ans;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
               swap(mx,mn);
            }

            mx=max(nums[i],mx*nums[i]);
            mn=min(nums[i],mn*nums[i]);
            ans=max(ans,mx);
        }
        return ans;    
    }
};

/* Approach 3 */

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int ans = INT_MIN;
        int prod = 1;
        
        for(int i=0;i<nums.size();i++)
        {
            prod=prod*nums[i];
            ans=max(prod,ans);
            if(prod==0)
            {
                prod=1;
            }
        }
        
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            prod=prod*nums[i];
            ans =max(ans,prod);
            if(prod==0)
            {
                prod=1;
            }
        }
        return ans;
    }
};
