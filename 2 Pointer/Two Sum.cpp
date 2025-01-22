/* Time :- O(Nlogn) --> Sorting Space :- O(N) */

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int low=0;
        int high=nums.size()-1;   
        vector<pair<int,int>>vec;
        
        for(int i=0;i<nums.size();i++)
        {
            vec.push_back({nums[i],i});
        }

        sort(vec.begin(),vec.end());

        while(low<=high)
        {
            long long sum = vec[low].first + vec[high].first;

            if(sum==target)
            {   
                return {vec[low].second,vec[high].second};
            }
            else if(sum > target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        return {};      
    }
};
