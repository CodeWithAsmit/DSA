/* Recursive approach :- Time :- LOG(N) Space :- LOG(N) (due to recursion stack) */

class Solution
{
public:
    int solve(int low, int high, vector<int>& nums)
    {
        if (low == high)
        {
            return nums[low];
        }

        int mid = low + (high - low) / 2;

        if (mid > 0 && nums[mid] == nums[mid - 1])
        {
            int leftCount = mid - 1 - low;  
            int rightCount = high - mid;

            if (leftCount % 2 == 0)
            {
                return solve(mid + 1, high, nums);
            }
            else
            {
                return solve(low, mid - 2, nums);
            }
        }
        else if (mid < high && nums[mid] == nums[mid + 1])
        {
            int leftCount = mid - low;      
            int rightCount = high - (mid + 1);

            if (leftCount % 2 == 0)
            {
                return solve(mid + 2, high, nums);
            }
            else
            {
                return solve(low, mid - 1, nums);
            }
        }
        else
        {
            return nums[mid];
        }
    }
    int singleNonDuplicate(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        return solve(low, high, nums);
    }
};

/* Iterative approach :- Time :- LOG(N) Space :- O(1) */

class Solution
{
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size() ;
        int l = 0;
        int r = n-1 ;
        int ans;
        
        while(l<=r)
        {
            int mid = (l + r)/2 ;
            if(mid%2) 
            {
                mid--;                             
            }
            if(mid+1 < n && nums[mid] == nums[mid+1])       
            {
                l = mid+2;                                  
            }
            else                                            
            {
               r = mid-1;
               ans = nums[mid];
            }
        }
        return ans;
    }
};
