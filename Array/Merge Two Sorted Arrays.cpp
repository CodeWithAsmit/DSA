/* Naive Approach Merge Function */

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
          vector<int>v;
          int i=0;
          int j=0;
          while(i<m&&j<n)
          {
              if(nums1[i]>nums2[j])
              {
                  v.push_back(nums2[j]);
                  j++;
              }
              else
              {
                  v.push_back(nums1[i]);
                  i++;
              }
          }
          while(i<m)
          {
             v.push_back(nums1[i]);
             i++;
          }
          while(j<n)
          {
              v.push_back(nums2[j]);
              j++;
          }
          for(int i=0;i<(m+n);i++)
          {
              nums1[i]=v[i];
          }
    }
};

/* Efficient Approach Time :- O(N + M) and constant space */

class Solution
{
public:
    void merge(vector<int>& nums1, int nums1Size, vector<int>& nums2, int nums2Size)
    {
        int i=nums1Size-1;
        int j=0;

        while(i>=0 && j<nums2Size)
        {
            if(nums1[i] > nums2[j])
            {
                swap(nums1[i],nums2[j]);
                i--;
                j++;
            }
            else
            {
                break;
            }
        }
        
        i = nums1Size;
        j = 0;

        while(i<nums1.size() && j<nums2.size())
        {
            nums1[i] = nums2[j];
            i++;
            j++;
        }
        sort(nums1.begin(),nums1.end());
    }
};
