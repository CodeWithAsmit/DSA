/* Time :- O(N) Space :- O(N) */

class Solution
{
  public:
    bool twoSum(vector<int>& arr, int target)
    {
        unordered_map<int,int>map;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<target)
            {
                if(map.find(target - arr[i]) != map.end())
                {
                    return 1;
                }
                else
                {
                    map[arr[i]] = i;
                }
            }
        }
        return 0;
    }
};

