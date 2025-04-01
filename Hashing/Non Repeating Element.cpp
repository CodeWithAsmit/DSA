/* Time :- O(N) Space :- O(N) */

class Solution
{
  public:
    int firstNonRepeating(vector<int>& arr)
    {
        unordered_map<int,int>mapFreq;
        
        for(int i=0;i<arr.size();i++)
        {
            if (mapFreq.find(arr[i])==mapFreq.end())
            {
               mapFreq[arr[i]] = 1;
            }
            else
            {
                mapFreq[arr[i]]++;
            }
        }
        
        for(int i=0;i<arr.size();i++)
        {
            if(mapFreq[arr[i]] == 1)
            {
                return arr[i];
            }
        }
        
        return 0;
    }
};
