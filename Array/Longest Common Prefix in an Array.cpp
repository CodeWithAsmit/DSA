/* Time :- O(Nlogn) and Space :- O(L), where L is length of arr[n-1] after sorting */

class Solution
{
  public:
    string longestCommonPrefix(vector<string> arr)
    {
        sort(arr.begin(),arr.end());
        
        int n = arr.size();
        int minLength = arr[0].size();
        
        string ans="";
        string minLengthString=arr[0];
        string maxLengthString=arr[n-1];
        
        for(int i=0;i<minLength;i++)
        {
            if(minLengthString[i]==maxLengthString[i])
            {
                ans.push_back(minLengthString[i]);
            }
            else
            {
                break;
            }
        }
        
        return ans;
    }
};
