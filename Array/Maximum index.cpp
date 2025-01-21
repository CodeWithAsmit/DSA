class Solution
{
  public:
    int maxIndexDiff(vector<int>& arr)
    {
        int n=arr.size();
        int i=0;
        int j=n-1;
        int ans=INT_MIN;
        
        vector<int>leftToRightMin(n,0);
        vector<int>RightToLeftMax(n,0);
        
        leftToRightMin[0] = arr[0];
        for(i=1;i<n;i++)
        {
            leftToRightMin[i] = min(leftToRightMin[i-1],arr[i]);
        }
        
        RightToLeftMax[n-1] = arr[n-1];
        for(i=n-2;i>=0;i--)
        {
            RightToLeftMax[i] = max(RightToLeftMax[i+1],arr[i]);
        }
        
        i=0;
        j=0;
        
        while(i<n && j<n)
        {
            if(leftToRightMin[i]<=RightToLeftMax[j])
            {
                ans = max(ans,j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
