/* Time :- O(N) and Space :- O(1) */

class Solution
{
public:
    void revArray(vector<int>& nums, int low, int high)
    {
        while(low<high)
        {
            swap(nums[low],nums[high]);
            low++;
            high--;
        }
    }
    void rotate(vector<int>& nums, int k)
    {
        int n= nums.size();
        
        if(k>n)
        {
            k = k%n;
        }

        int low = 0;
        int high = n-k-1;
        revArray(nums,low,high);

        low = n-k;
        high = n-1;
        revArray(nums,low,high);
        
        low = 0;
        high = n-1;
        revArray(nums,low,high);
    }
};
