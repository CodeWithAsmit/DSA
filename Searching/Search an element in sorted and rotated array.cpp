/* Time :- O(logn) Space :- O(1) */

/* Approach 1 */

class Solution
{
public:
    int bSearch(int low,int high,vector<int>& nums, int target)
    {  
        while(low<=high)
        {
            int mid = high + (low - high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
    }
    int findMin(vector<int>& nums)
    {
        int low=0;
        int high = nums.size()-1;

        while(low<=high)
        {
            int mid = high + (low - high)/2;
            
            bool leftOk = (mid == 0) || (nums[mid] < nums[mid - 1]);
            bool rightOk = (mid == nums.size() - 1) || (nums[mid] < nums[mid + 1]);
            
            if(leftOk && rightOk)
            {
                return mid;
            }
            else if(nums[mid] > nums[high])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return -1;    
    }
    int search(vector<int>& nums, int target)
    {
        int ans=-1;
        int n = nums.size()-1;
        
        if(nums[n] > nums[0])
        {
            return bSearch(0,n,nums,target);
        }

        int index = findMin(nums);

        if(nums[index]==target)
        {
            return index;
        }

        if(target >= nums[0])
        {
            ans = bSearch(0,index-1,nums,target);
        }
        else
        {
            ans = bSearch(index+1,n,nums,target);
        }
        return ans;
    }
};

/* Approach 2 */

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int low=0;
        int high=nums.size()-1;
        int mid;
        
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>=nums[low])
            {
                if(nums[mid]>=target && target>=nums[low])
                {
                    high=mid-1;
                }
                else 
                {
                    low=mid+1;
                }
            }
            else 
            {
                if(nums[high]>=target && target>=nums[mid])
                {
                    low=mid+1;
                }
                else 
                {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
