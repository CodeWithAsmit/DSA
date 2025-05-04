/* Time :- O(M + N) Space :- O(1) */

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        int low = 0;
        int high = colCount - 1;
        
        while(low<rowCount && high>=0)
        {
            if(matrix[low][high]==target)
            {
                return 1;
            }
            else if(matrix[low][high] > target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        return 0;
    }
};
