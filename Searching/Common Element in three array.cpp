/* Approach 1 (STL) Time :- O(m+n) Space :- O(m+n) */

class Solution
{
       public: 
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
       {
              set<int>s1,s2,s3;
              vector<int>v;
              for(int i=0;i<n1;i++)
              {
                  s1.insert(A[i]);
              }
              for(int i=0;i<n2;i++)
              {
                  if(s1.find(B[i])!=s1.end())
                  {
                      s2.insert(B[i]);
                  }
              }
              for(int i=0;i<n3;i++)
              {
                  if(s2.find(C[i])!=s2.end())
                  {
                      s3.insert(C[i]);
                  }
              }
              set<int>::iterator itr;
              for (itr=s3.begin(); itr != s3.end(); itr++)
              {
                  v.push_back(*itr);
              }
              return v;
        }
};

/* Approach 2 (Binary Search) --> Time :- Suppose MIN of N1, N2, N3 is N1 --> O[N1*log(N2*N3)] and Space :- O(1) */

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
                return 1;
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
        return 0;
    }
    
    vector<int> solve(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
    {
        vector<int> ans;
        
        for (auto it : arr1)
        {
            bool search1 = search(arr2, it);
            bool search2 = search(arr3, it);
            
            if (search1 && search2)
            {
                if (ans.empty() || ans.back() != it)
                {
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
    
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,vector<int> &arr3)
    {
        if (arr1.size() <= arr2.size() && arr1.size() <= arr3.size())
        {
            return solve(arr1, arr2, arr3);
        }
        else if (arr2.size() <= arr1.size() && arr2.size() <= arr3.size())
        {
            return solve(arr2, arr1, arr3);
        }
        else
        {
            return solve(arr3, arr1, arr2);
        }
    }
};

/* Approach 3 (2 Pointer Approach) --> Time :- O(N1 + N2 + N3) and Space :- O(1) --> Most Optimal Approach */

class Solution
{
public:
    vector<int> commonElements(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3)
    {
        int i = 0, j = 0, k = 0;
        vector<int> ans;

        while (i < arr1.size() && j < arr2.size() && k < arr3.size())
        {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
            {
                if (ans.empty() || ans.back() != arr1[i])
                {
                    ans.push_back(arr1[i]);
                }

                i++;
                j++;
                k++;
            }
            else
            {
                int minVal = min({arr1[i], arr2[j], arr3[k]});
                if (arr1[i] == minVal)
                {
                    i++;
                }
                if (arr2[j] == minVal)
                {
                    j++;
                }
                if (arr3[k] == minVal)
                {
                    k++;
                }
            }
        }

        if (ans.empty())
        {
            return {-1};
        }
        return ans;
    }
};
