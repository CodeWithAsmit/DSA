/* Approach 1 --> Recursion Time :- O() Space :- O() */

class Solution
{
    public:
    int solve(int curRow, int curCol, int totalRow, int totalCol)
    {
        if(curRow<0 || curCol<0)
        {
            return 0;
        }
        
        if(curRow==0 || curCol==0)
        {
            return 1;
        }
        
        int wayUp = solve(curRow-1, curCol, totalRow, totalCol);
        int wayLeft = solve(curRow, curCol-1, totalRow, totalCol);
        return wayUp + wayLeft;
    }
    
    int numberOfPaths(int m, int n)
    {
        return solve(m-1,n-1,m,n);
    }
};

/* Approach 2 --> Recursion Memorized :- O() Space :- O() */

class Solution
{
    public:
    int pathMemo[101][101];
    int solve(int curRow, int curCol, int totalRow, int totalCol)
    {
        if(curRow<0 || curCol<0)
        {
            return 0;
        }
        
        if(curRow==0 || curCol==0)
        {
            return 1;
        }
        
        if(pathMemo[curRow][curCol]!=-1)
        {
            return pathMemo[curRow][curCol];
        }
        
        int wayUp = solve(curRow-1, curCol, totalRow, totalCol);
        int wayLeft = solve(curRow, curCol-1, totalRow, totalCol);
        return pathMemo[curRow][curCol] = wayUp + wayLeft;
    }
    
    int numberOfPaths(int m, int n)
    {
        memset(pathMemo, -1, sizeof(pathMemo));
        return solve(m-1,n-1,m,n);
    }
};


/* Efficient Approach 2 --> DP Time :- O(m*n) Space :- O(m*n) */

int dp[11][11]={0};

long long  numberOfPaths(int m, int n)
{
    if(m==1||n==1)
    {
        return dp[m][n] = 1;
    }
    else if(dp[m][n]!=0)
    {
        return dp[m][n];
    }
    else
    {
        return dp[m][n] = numberOfPaths(m,n-1) + numberOfPaths(m-1,n);
    }
}
