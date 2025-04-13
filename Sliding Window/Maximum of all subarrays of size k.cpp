/* Approach 1 :- Time :- O(N*K) Space :- O(K) */

class Solution
{
  public:
  
    int findMaxValue(unordered_map<int,int> &map)
    {
        int maxValue = INT_MIN;
        
        for(auto it : map)
        {
            maxValue = max(maxValue,it.second);
        }
        
        return maxValue;
    }
    
    vector<int> maxOfSubarrays(vector<int>& arr, int k)
    {
        if(k==1)
        {
            return arr;
        }
        
        int i=0;
        int j=0;
        int maxValue = INT_MIN;
        
        vector<int>ans;
        unordered_map<int,int>map;
        
        while(j<arr.size())
        {
            if(j-i+1 == k)
            {
                map.erase(i);
                map[j] = arr[j];
                
                maxValue = max(maxValue,arr[j]);
                ans.push_back(maxValue);
                
                if(arr[i] == maxValue)
                {
                    maxValue = findMaxValue(map);
                }
                
                i++;
                j++;
            }
            else
            {
                map[j] = arr[j];
                maxValue = max(maxValue,arr[j]);
                j++;
            }
        }
        return ans;
    }
};

/* Approach 2 :- Time :- O(N) Space :- O(K) */

class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        int i=0;
        int j=0;
        vector<int>v;
        list<int>l;
        while(j<n)
        {
            while(l.size()>0&&l.back()<arr[j])
            {
                l.pop_back();
            }
            l.push_back(arr[j]);
            if(j-i+1==k)
            {
                v.push_back(l.front());
                if(l.front()==arr[i])
                {
                    l.pop_front();
                }
                i++;
                j++;
            }
            else 
            {
                j++;
            }
        }
        return v;
    }
};
