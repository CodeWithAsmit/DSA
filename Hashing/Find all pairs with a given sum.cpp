class Solution
{
  public:
    vector<pair<int, int>> allPairs(int target, vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> freqMap;
        vector<pair<int,int>> ans;

        for(int i = 0; i < arr2.size(); i++)
        {
            freqMap[arr2[i]]++;
        }

        for(int i = 0; i < arr1.size(); i++)
        {
            if(freqMap.find(target - arr1[i]) != freqMap.end())
            {
                for(int j = 0; j < freqMap[target - arr1[i]]; j++)
                {
                    ans.push_back({arr1[i], target - arr1[i]});
                }
            }
        }
      
        sort(ans.begin(), ans.end());
        return ans;
    }
};
