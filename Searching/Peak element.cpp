/* Time :- O(logn) Space :- O(1) */

class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size()-1;

        while(low<=high)
        {
            int mid = high + (low-high)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                return mid;
            }
            else if(nums[mid]>nums[mid+1])
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
};
