/* Time :- O(logn) Space :- O(1) */

class Solution
{
public:
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
                return nums[mid];
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
};
