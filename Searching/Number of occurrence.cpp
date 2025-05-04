/* Approach 1 --> Using Hashmap to count the frequency --> Time :- O(N) Space :- O(N) */

/* Approach 2 --> Using Partially Binary Search Time :- O(N) Space :- O(1) */

class Solution
{
    public:
    int search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size()-1;

        while(low<=high)
        {
            int mid = high + (low-high)/2;

            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
    }
    
    int countFreq(vector<int>& arr, int target)
    {
        int pos = search(arr,target);
        
        if(pos==-1)
        {
            return 0;
        }
        
        int init = pos;
        int last = pos;
        
        while(arr[init]==target)
        {
            init--;
        }
        
        while(arr[last]==target)
        {
            last++;
        }
        
        return last-init-1;
    }
};

/* Approach 3 --> Using Binary Search Time :- O(logn) Space :- O(1) */

class Solution
{
public:
    int firstOccurance(vector<int>& arr, int n, int key)
    {
        int low=0;
        int high=n-1;
        int ans=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==key)
            {
                ans = mid;
                high = mid-1;
            }
            else if(key>arr[mid])
            {
                low = mid+1;
            }
            else if(key<arr[mid])
            {
                high = mid-1;
            }
        }
        return ans;
    }
    
    int lastOccurance(vector<int>& arr, int n, int key)
    {
        int low=0;
        int high=n-1;
        int ans=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==key)
            {
                ans = mid;
                low = mid+1;
            }
            else if(key>arr[mid])
            {
                low = mid+1;
            }
            else if(key<arr[mid])
            {
                high = mid-1;
            }
        }
        return ans;
    }
    
    vector<int> numOfOccurrences(vector<int>& nums, int target)
    {
        int n = nums.size();
        int first = firstOccurance(nums,n,target);
        int last =  lastOccurance(nums,n,target);    
        return last-first-1;
    }
};
