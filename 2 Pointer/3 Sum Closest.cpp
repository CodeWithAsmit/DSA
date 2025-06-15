/* Time :- O(N*N) Space :- O(1) */

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        int requiredSum = nums[0] + nums[1] + nums[2];

        for(int i=0;i<nums.size();i++)
        {
            int low = i+1;
            int high = nums.size()-1;

            while(low<high)
            {
                int currentSum = nums[i] + nums[low] + nums[high];

                if(currentSum==target)
                {
                    return target;
                }
                else if(currentSum > target)
                {
                    high--;
                }
                else
                {
                    low++;
                }

                if(abs(target - requiredSum) > abs(target - currentSum))
                {
                    requiredSum = currentSum;
                }
            }
        }
        return requiredSum;    
    }
};
