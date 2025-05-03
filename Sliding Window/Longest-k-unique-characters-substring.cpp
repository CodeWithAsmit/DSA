/* Time :- O(N) Space :- O(K) */

class Solution
{
  public:
    int longestKSubstr(string &s, int k)
    {
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        unordered_map<char,int>charTrack;
        
        while(j<s.length())
        {
            charTrack[s[j]]++;
            
            if(charTrack.size() == k)
            {
                ans = max(ans,j-i+1);
            }
            else if(charTrack.size() > k)
            {
                while(charTrack.size() > k)
                {
                    if(charTrack.find(s[i]) != charTrack.end())
                    {
                        charTrack[s[i]]--;
                        if(charTrack[s[i]] == 0)
                        {
                            charTrack.erase(s[i]);
                        }
                    }
                    i++;
                }
                if(charTrack.size() == k)
                {
                    ans = max(ans,j-i+1);
                }
            }
            j++;
        }
        return ans == INT_MIN ? -1 : ans;
    }
};
