/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int count1=0;
        int count2=0;
        int n = nums.size();
        int firstMajorityElement=0;
        int secondMajorityElement=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i] == firstMajorityElement)
            {
                count1++;
            }
            else if (nums[i] == secondMajorityElement)
            {
                count2++;
            }
            else if(count1==0)
            {
                count1=1;
                firstMajorityElement = nums[i];
            }
            else if (count2==0)
            {
                count2=1;
                secondMajorityElement =  nums[i];
            } 
            else
            {
                count1--;
                count2--;
            }
        }

        vector<int>ans;
        int firstVerifyCount = 0;
        int secondVerifyCount = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==firstMajorityElement)
            {
                firstVerifyCount++;
            }
            else if(nums[i]==secondMajorityElement)
            {
                secondVerifyCount++;
            }
        }

        if(firstVerifyCount > (n/3))
        {
            ans.push_back(firstMajorityElement);
        }
        if(secondVerifyCount > (n/3))
        {
            ans.push_back(secondMajorityElement);
        }
        return ans;
    }    
};
