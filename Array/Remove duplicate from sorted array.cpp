/* Approach 1 */

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            int temp = nums[i];
            while(i<nums.size()&&temp==nums[i])
            {
                i++;
            }
            i--;
            nums[count++]=temp;
        }
        return count;    
    }
};

/* Approach 2 */

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i=0;
        int j=1;
        int ans=1;

        while(i<nums.size() && j < nums.size())
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i] = nums[j];
                ans++;
            }
            j++;
        }
        return ans;
    }
};
