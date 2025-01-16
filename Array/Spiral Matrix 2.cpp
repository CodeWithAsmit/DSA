class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>>ans(n,vector<int>(n));
        
        int top=0;
        int left=0;        
        int right=n-1;
        int down=n-1;
        
        int count=1;
        
        while(top<=down && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                ans[top][i]=count++;
            }
            top++;

            for(int i=top;i<=down;i++)
            {
                 ans[i][right]=count++;
            }
            right--;

            if(top<=down)
            {
                for(int i=right;i>=left;i--)
                {
                     ans[down][i]=count++;
                }
                down--;
            }

            if(left<=right)
            {
                for(int i=down;i>=top;i--)
                {
                     ans[i][left]=count++;
                }
                left++;
            }
        }
        return ans;
    }
};
