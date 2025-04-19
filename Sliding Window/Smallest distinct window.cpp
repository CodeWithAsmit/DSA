/* Approach 1 :- Time :- O(N*N) Space :- O(number of unique characters in str) --> Brute Force Approach */

class Solution
{
  public:
    int findUniqueCharCount(string &s)
    {
        int count = 0;
        bool visited[52] = {0};
    
        for (char ch : s)
        {
            int idx;
            
            if (ch >= 'A' && ch <= 'Z')
            {
                idx = ch - 'A';
            }
            else
            {
                idx = ch - 'a' + 26; 
            }
    
            if (!visited[idx])
            {
                visited[idx] = 1;
                count = count + 1;
            }
        }
        return count;
    }
    
    int findSubString(string& str)
    {
        int i=0;
        int j=0;
        int ans=INT_MAX;
        
        string temp="";
        int stringInputCount = findUniqueCharCount(str);
        
        while(j<str.length())
        {
            temp.push_back(str[j]);
            
            int tempStringInput = findUniqueCharCount(temp);
            
            if(tempStringInput == stringInputCount)
            {
                ans = min(ans, static_cast<int>(temp.length()));
                
                while(temp.length() && findUniqueCharCount(temp) == stringInputCount)
                {
                    ans = min(ans, static_cast<int>(temp.length()));
                    temp.erase(0,1);
                }
                j++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};

/* Approach 2 :- Time :- O(N) Space :- O(Number of unique charecter in str) */

class Solution
{
    public:
    int findSubString(string str)
    {
       unordered_map<char,int>mp;  
       for(auto x : str)
       {
           mp[x]++;
       }
       
       int i=0;
       int j=0;
       int unique=mp.size();
       int ans=INT_MAX;
       mp.clear();
       
       while(j<str.length())
       {
           mp[str[j]]++;
           
           if(mp.size()==unique)
           {
               while(i<=j&&mp.size()==unique)
               {
                   if(mp[str[i]]==1)
                   {
                       int window=j-i+1;
                       ans=min(ans,window);
                       break;
                   }
                   else
                   {
                       mp[str[i]]--;
                       i++;
                   }
               }
               j++;
           }
           else
           {
               j++;
           }
       }
       return ans;
    }
};
