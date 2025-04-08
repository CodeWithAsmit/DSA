/* Time :- O(N) Space :- O(N) */

class Solution
{   
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int temp=k-arr[i];
            if(mp[temp])
            {
                ans=ans+mp[temp];
            }
            mp[arr[i]]++;
        }
        return ans;
    }
};

/* New question updated code - Time :- O(nlogn) Space :- O(n) */

class Solution
{
  public:
    vector<vector<int>> getPairs(vector<int>& arr)
    {
        set<vector<int>>tempSet;
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++)
        {
            int temp = -arr[i];
            
            if(mp.find(temp)!=mp.end())
            {
                if(temp>0)
                {
                    temp = -temp;
                }
                tempSet.insert({temp,-temp});
            }
            else
            {
                if(mp.find(arr[i])==mp.end())
                {
                    mp[arr[i]] = i;
                }
            }
        }
        return vector<vector<int>>(tempSet.begin(), tempSet.end());
    }
};
