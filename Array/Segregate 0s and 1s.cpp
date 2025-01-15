/* Time is O(N) and Space is O(1) */

class Solution
{
  public:
    void segregate0and1(vector<int> &arr)
    {
        int low=0;
        int high=arr.size()-1;
        
        while(low<high)
        {
            if(arr[low]==1 && arr[high]==0)
            {
                swap(arr[low],arr[high]);
            }
            
            if(arr[high]==1)
            {
                high--;
            }
            if(arr[low]==0)
            {
                low++;
            }
        }
    }
};
