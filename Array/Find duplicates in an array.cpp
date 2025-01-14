/* Approach 1 */

class Solution
{
  public:
    vector<int> findDuplicates(vector<int>& arr)
    {
        unordered_set<int>dupNumCheck;
        vector<int>vec;
        
        for(auto it : arr)
        {
            if(dupNumCheck.find(it)==dupNumCheck.end())
            {
                dupNumCheck.insert(it);
            }
            else
            {
                vec.push_back(it);
            }
        }
        return vec;
    }
};

/* Approach 2 */

class Solution
{
  public:
    vector<int> duplicates(int arr[], int n)
    {
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            arr[arr[i]%n]+=n;
        }
        for(int i=0;i<n;i++)
        {
            arr[i]/=n;
            if(arr[i]>1)
            {
                v.push_back(i);
            }
        }
        if(v.size()==0)
        {
            v.push_back(-1);
        }
        return v;
    }
};

/* Approach 3 :- Without Modifying Array [ Concept :- Cycle Detection In Array ] */

class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        if(nums.size()>1)
        {
            int slow=nums[0];
            int fast=nums[nums[0]];
            
            while(slow!=fast)
            {
                slow=nums[slow];
                fast=nums[nums[fast]];    
            }
            
            fast=0;
            while(slow!=fast)
            {
                slow=nums[slow];
                fast=nums[fast];
            }
            return slow;
        }
        return -1;
    }
};
