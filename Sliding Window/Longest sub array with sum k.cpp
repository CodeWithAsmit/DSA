/* Time :- O(N) Space :- O(N) */

class Solution
{
  public:
    int longestSubarray(vector<int>& nums, int k)
    {
        int j=0;
        int sum = 0;
        int ans = INT_MIN;
        unordered_map<int,int>mp;
        
        mp[0] = 0;
        
        while(j < nums.size())
        {
            sum  = sum + nums[j];
            
            if(mp.find(sum)==mp.end())
            {
                mp[sum] = j + 1;
            }
        
            if(mp.find(sum - k) != mp.end())
            {
                ans = max(ans, j - mp[sum-k] + 1);
            }
            j++;
        }
        
        return ans == INT_MIN ? 0 : ans;
    }
};
