/* Time :- O(2^N) Space :- O(N) */

/* Solve function time complexity is O(1) and solve function is called O(2^n) times so overall time is --> O(2^n) */

class Solution
{
    public:
    void solve(int idx, vector<int> curVector, vector<int> &arr, vector<vector<int>> &result)
    {
        if(idx==arr.size())
        {
            result.push_back(curVector);
            return;
        }

        solve(idx + 1, curVector, arr, result);
        curVector.push_back(arr[idx]);
        solve(idx + 1, curVector, arr, result);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int>tempVector;
        vector<vector<int>>result;
        solve(0,tempVector,nums,result);
        return result;
    }
};
