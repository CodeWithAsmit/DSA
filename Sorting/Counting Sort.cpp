/*Over Array of integers*/

#include <bits/stdc++.h>

using namespace std;

void printarray(int arr[],int n)
{
   for(int i=0;i<n;i++)
   {
   	cout<<arr[i]<<" ";
   }
}

void counting(int arr[],int n,int k)
{
   int hash[k]={0};
   int temp[n];
   	
   for(int i=0;i<n;i++)
   {
   	hash[arr[i]]++;
   }
   for(int i=1;i<k;i++)
   {
   	hash[i]=hash[i]+hash[i-1];
   }
   for(int i=n-1;i>=0;i--)
   {
   	temp[hash[arr[i]]-1]=arr[i];
   	hash[arr[i]]--;
   }
   for(int i=0;i<n;i++)
   {
   	arr[i]=temp[i];
   }
}

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    
    cout<<"Array Before:-\n";
    printarray(arr,n);
    
    counting(arr,n,k);
    
    cout<<"\nArray after sorting:-\n";
    printarray(arr,n);
    return 0;
}

/* Over a string */

class Solution
{
    public:
    string countSort(string s)
    {
        int n=s.length();
        char ans[n];
        int hash[26]={0};
        string res="";
        for(int i=0;i<n;i++)
        {
            hash[s[i]-97]++;
        }
        for(int i=1;i<26;i++)
        {
            hash[i]=hash[i]+hash[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            hash[s[i]-97]--;
            int temp=hash[s[i]-97];
            ans[temp]=s[i];
        }
        for(int i=0;i<n;i++)
        {
            res+=ans[i];
        }
        return res;
    }
};
