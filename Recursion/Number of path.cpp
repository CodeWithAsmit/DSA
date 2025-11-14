/* Approach 1 --> Recursion --> Time :- O(2^(m+n)) Space :- O(m+n) */

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

/* Approach 2 --> Recursion Memorized --> Time :- O(m*n) Space :- O(m*n) */

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


/* Approach 3 --> DP --> Time :- O(m*n) Space :- O(m*n) */

class Solution
{
    public:
    int pathDP[101][101]={0};
    int numberOfPaths(int m, int n)
    {
        if(m==1||n==1)
        {
            return pathDP[m][n] = 1;
        }
        else if(pathDP[m][n]!=0)
        {
            return pathDP[m][n];
        }
        else
        {
            return pathDP[m][n] = numberOfPaths(m,n-1) + numberOfPaths(m-1,n);
        }
    }
};

/* Approach 4 --> NCR --> Time :- O(min(m, n)) Space :- O(1) */

class Solution
{
    public:
    long long nCr(int n, int r)
    {
        if (r > n - r)
        {
            r = n - r;
        }
        
        long long res = 1;

        for (int i = 1; i <= r; i++)
        {
            res = res * (n - r + i) / i;
        }

        return res;
    }

    long long numberOfPaths(int m, int n)
    {
        int totalMoves = m + n - 2;
        int downMoves = m - 1;
        return nCr(totalMoves, downMoves);
    }
};
