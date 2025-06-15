/* Approach 1 :- O(N*N*N) and O(1) (excluding output) */

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        vector<vector<int>> ans;

        if (n < 4) 
        {
            return {};
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int low = j + 1;
                int high = n - 1;
                long long sum = (long long)target - nums[i] - nums[j];

                while (low < high)
                {
                    long long twoSum = nums[low] + nums[high];

                    if (twoSum == sum)
                    {
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
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
                    else if (twoSum < sum)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};

/* Approach 2 :- O(N*N*N*logk) (due to set insertion) and O(k) */

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        if (n < 4)
        {
            return {};
        }
        
        set<vector<int>> tempSet;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int low = j + 1;
                int high = n - 1;

                while (low < high)
                {
                    long long temp = (long long)nums[i] + nums[j] + nums[low] + nums[high];

                    if (temp == target)
                    {
                        tempSet.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                    }
                    else if (temp > target)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
            }
        }
        for (auto it : tempSet)
        {
            result.push_back(it);
        }
        return result;
    }
};
