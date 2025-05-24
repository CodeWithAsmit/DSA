/* Approach 1 Using Hashmap Time :- O(N) Space :- O(N) */

/* Approach 2 Using Voting Algorithms Time :- O(N) Space :- O(1) */

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int count=0;
        int majorityElement=0;

        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                count++;
                majorityElement = nums[i];
            }
            else if(nums[i]==majorityElement)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return majorityElement;
    }
};
