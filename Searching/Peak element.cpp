/* Time :- O(logn) Space :- O(1) */

class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            bool leftOk = (mid == 0) || (nums[mid] > nums[mid - 1]);
            bool rightOk = (mid == nums.size() - 1) || (nums[mid] > nums[mid + 1]);

            if(leftOk && rightOk)
            {
                return mid;
            }
            else if(mid > 0 && nums[mid - 1] > nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
};
