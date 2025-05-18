/* Approach 1 Time :- O(N*N*logk) Space :- O(k) */

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
      priority_queue <int> pq;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               pq.push(mat[i][j]);
               if(pq.size()>k)
               {
                   pq.pop();
               }
           }
       }
       return pq.top();
}

/* Approach 2 Time :- O(N * log(max_val - min_val)) Space :- O(1) */

class Solution
{
    public:
    int solve(int row,int col,vector<vector<int>>& matrix, int val) /* This is O(N) */
    {
        int low = 0;
        int high = col-1;
        int ans = 0;

        while(low<col && high >= 0)
        {
            if(matrix[low][high] > val)
            {
                high--;
            }
            else
            {
                low++;
                ans = ans + high + 1;
            }
        }
        return ans;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[row-1][col-1];
        int ans = -1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int smallElementCount = solve(row,col,matrix,mid);

            if(smallElementCount < k)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;    
    }
};
