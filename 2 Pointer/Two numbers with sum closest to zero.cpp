/* Time :- O(Nlogn) Space :- O(1) */

class Solution
{
    public:
    int closestToZero(int nums[], int n)
    {
        sort(nums, nums + n);

        int low = 0;
        int high = n-1;
        int ans = INT_MAX;

        while (low < high)
        {
            int sum = nums[low] + nums[high];
            
            if (abs(ans) > abs(sum) || (abs(ans) == abs(sum) && sum > ans))
            {
                ans = sum;
            }

            if (sum == 0)
            {
                return 0;
            }
            else if (sum > 0)  /* Move Close To Zero So Need Less Value of Sum */
            {
                high--;
            }
            else               /* Move Close To Zero So Need More Value of Sum */
            {
                low++;
            }
        }
        return ans;
    }
};
