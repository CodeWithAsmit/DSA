/* Time :- O(N∗M∗Log(Min(N,M))) Space :- O(M*N) */

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
    {
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                mp[j-i].push(mat[i][j]);
            }
        }
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                mat[i][j]=mp[j-i].top();
                mp[j-i].pop();
            }
        }
        return mat;
    }
};
