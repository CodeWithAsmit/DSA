/* Time :- O(N*N) Space :- O(N) --> Optimised Brute Force */

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0;
        int len = s.length();

        for (int i = 0; i < len; ++i)
        {
            unordered_set<char> seenChars;
            for (int j = i; j < len; ++j)
            {
                char currentChar = s[j];
                if (seenChars.count(currentChar))
                {
                    break;
                }
                else
                {
                    seenChars.insert(currentChar);
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        return maxLength;
    }
};

/* Time :- O(N) Space :- O(K) */

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
      if(s.length()==0)
      {
          return 0;
      }
      unordered_map<char,int>m;
      int i=0;
      int j=0;
      int maxi=INT_MIN;
      
        while(j<s.length())
        {    
            m[s[j]]++;   
            if(m.size()==j-i+1)
            {
                maxi=max(maxi,j-i+1);
                j++;
            }
            else if(m.size()<j-i+1)
            {
                while(m.size()<j-i+1)
                {
                    m[s[i]]--;
                    if(m[s[i]]==0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;    
    }
};

/* Time :- O(N) Space :- O(K) --> More optimal approach with same time and space as it is not calculating freq. just checking the presence */

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;
        int maxLength = 0;
        unordered_set<char> seen;

        while (j < s.length())
        {
            if (seen.find(s[j]) == seen.end())
            {
                seen.insert(s[j]);
                maxLength = max(maxLength, j - i + 1);
                j++;
            }
            else
            {
                seen.erase(s[i]);
                i++;
            }
        }
        return maxLength;
    }
};
