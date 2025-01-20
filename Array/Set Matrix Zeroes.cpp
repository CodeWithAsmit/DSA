/* Approach :- 1 Using Queue DS */

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        queue<pair<int,int>> q;
        int row = matrix.size();
        int col = matrix[0].size();  
        
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                if(matrix[i][j]==0)
                {
                    q.push(make_pair(i,j));
                }
            }
        }
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int r=0; r<row; r++)
            {
                matrix[r][y]=0;
            }
            for(int c=0; c<col; c++)
            {
                matrix[x][c]=0;
            }
        }
    }
};

/* Approach :- 2 --> Using Array */

class Solution
{
public:
    void setZeroes(vector<vector<int>>& arr)
    {
        int row[200]={0};
        int col[200]={0};

        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                if(arr[i][j]==0)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i=0;i<200;i++)
        {
            if(row[i]==1)
            {
                for(int j=0;j<arr[0].size();j++)
                {
                    arr[i][j]=0;
                }
            }
            if(col[i]==1)
            {
                for(int j=0;j<arr.size();j++)
                {
                    arr[j][i]=0;
                }
            }
        }  
    }
};

/* Approach :-3 Most Efficient */

void setZeroes(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    
    bool firstRowZero = false;
    bool firstColZero = false;
    
    // Check if the first row needs to be zeroed
    for (int j = 0; j < n; j++) 
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }
    
    // Check if the first column needs to be zeroed
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }
    
    // Use the first row and column as markers
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0; // Mark the row
                matrix[0][j] = 0; // Mark the column
            }
        }
    }
    
    // Set the cells to zero based on markers
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Handle the first row
    if (firstRowZero)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }
    
    // Handle the first column
    if (firstColZero)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }
}
