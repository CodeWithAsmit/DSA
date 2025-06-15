/* Time :- O(N*N) Space :- O(1) */

class Solution
{
    public:
    int countTriplet(vector<int>& arr)
    {
        int count=0;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++)
        {
            int low=0;
            int high=arr.size()-1;
            
            while(low<high)
            {
                if(arr[low]+arr[high]==arr[i])
                {
                    count++;
                    low++;
                    high--;
                }
                else if(arr[low]+arr[high]<arr[i])
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        return count;
    }
};
