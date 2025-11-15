/* Time :- O(2^N) Space :- O(2^N) */

class Solution
{
  public:
    void solve(int idx, int curSum, vector<int> &arr, vector<int> &result)
    {
        if(idx==arr.size())
        {
            result.push_back(curSum);
            return;
        }
        
        int curNumInclude = curSum + arr[idx];
        solve(idx + 1, curSum, arr, result);
        solve(idx + 1, curNumInclude, arr, result);
        return;
    }
    vector<int> subsetSums(vector<int>& arr)
    {
        vector<int>result;
        solve(0,0,arr,result);
        return result;
    }
};
