/* Time :- O(N*N) Space :- O(N) */

/* Approach 1 :- very least efficient */

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>>ans;
        set<vector<int>>filterVector;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            int low = i+1;
            int high = nums.size()-1;

            while(low<high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if(sum==0)
                {
                    filterVector.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }
                else if(sum>0)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
        for(auto it : filterVector)
        {
            ans.push_back(it);
        }
        return ans;
    }
};

/* Approch 2:- Efficient */

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;    
        sort(nums.begin(), nums.end());  

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int low = i + 1;
            int high = nums.size() - 1;

            while (low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == 0)
                {
                    res.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    high--;

                    while (low < high && nums[low] == nums[low - 1])
                    {
                        low++;
                    }
                    while (low < high && nums[high] == nums[high + 1])
                    {
                        high--;
                    }
                }
                else if (sum > 0)
                {
                    high--;
                }
                else
                {
                    low++;
                }                   
            }  
        }
        return res;
    }
};

/*Approach 3 :- Most Efficient approach*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();  
        vector<vector<int>>v;
        set<vector<int>>ans;
        sort(nums.begin(), nums.end());  
            
        for(int i = 0; i < n-2; i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            int start = i+1;
            int end = nums.size()-1;
            while(start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum==0)
                {
                    ans.insert({nums[i], nums[start], nums[end]});
                }
                if(sum < 0)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        for(auto i : ans)
        {
            v.push_back(i);
        }
        return v;
    }
};
