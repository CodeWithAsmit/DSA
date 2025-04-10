/* Time :- O(N) and Space :- O(1) */

class Solution
{
public:	
	int shortestDistance(vector<string> &s, string word1, string word2)
	{
	    int ans = INT_MAX;
	    int first = -1;
	    int second = -1;
	    
	    for(int i = 0; i < s.size(); i++)
	    {
	        if(s[i] == word1)
	        {
	            first = i;
	        }
	        else if(s[i] == word2)
	        {
	            second = i;
	        }
	        
	        if(first != -1 && second != -1)
	        {
	            ans = min(ans, abs(second - first));
	        }
	    }
	    
	    return ans == INT_MAX ? 0 : ans;
	}
};
