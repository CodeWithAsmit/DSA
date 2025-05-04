/* Approach 1 :- Time :- O(logn) [Best and Average] O(N) [Worst Case] Space :- O(1) */

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
    vector<int> searchRange(vector<int>& arr, int target)
    {
        if(arr.empty())
        {
            return {-1, -1};
        }

        int pos = search(arr, target);

        if(pos == -1)
        {
            return {-1, -1};
        }

        int init = pos;
        int last = pos;

        while(init - 1 >= 0 && arr[init - 1] == target)
        {
            init--;
        }

        while(last + 1 < arr.size() && arr[last + 1] == target)
        {
            last++;
        }
        return {init, last};
    }
};

/* Approach 2 :- Time :- O(logn) Space :- O(1) */

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
    
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        int first = firstOccurance(nums,n,target);
        int last =  lastOccurance(nums,n,target);    
        return {first, last};
    }
};
