/* Approach 1 */

class Solution
{
    public:
    void pushZerosToEnd(vector<int>& arr)
    {
        int nonZeroIndex = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=0)
            {
                arr[nonZeroIndex++] = arr[i];
            }
        }
        
        while(nonZeroIndex < arr.size())
        {
            arr[nonZeroIndex++] = 0;
        }
    }
};

/* Approach 2 */

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int i=0;
        int j=0;
        
        while(i<nums.size()&&j<nums.size())
        {
            if(nums[i]==0&&nums[j]!=0)
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[i]==0&&nums[j]==0)
            {
                j++;
            }
            else if(nums[i]!=0&&nums[j]!=0)
            {
                i++;
                j++;
            }
        }
    }
};
