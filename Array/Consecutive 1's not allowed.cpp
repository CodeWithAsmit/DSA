/* Time :- O(N) and Space :- O(N) */

class Solution
{
  public:
    int countStrings(int n)
    {
        int a[n], b[n];
        a[0] = b[0] = 1;
     
        for (int i = 1; i < n; i++)
        {
            a[i] = a[i - 1] + b[i - 1];
            b[i] = a[i - 1];
        }
        return a[n - 1] + b[n - 1];
    }
};

/* Time :- O(N) and Space :- O(1) */

class Solution
{
public:
    int countStrings(int n) 
    {
        int a_prev = 1, b_prev = 1;
        int a_curr, b_curr;
        
        for (int i = 1; i < n; i++)
        {
            a_curr = a_prev + b_prev;
            b_curr = a_prev;
            a_prev = a_curr;
            b_prev = b_curr;
        }
        return a_prev + b_prev;
    }
};

/* When to generate string as well. */

class Solution
{
  public:
    void generateStrings(int n, int zerolimit, int onelimit, string current, vector<string>& result, char prev)
    {
        if (current.length() == n)
    	{
            result.push_back(current);
            return;
        }
        
        if (zerolimit > 0)
    	{
            generateStrings(n, zerolimit - 1, onelimit, current + "0", result, '0');
        }
        
        if (onelimit > 0 && prev != '1')
    	{
            generateStrings(n, zerolimit, onelimit - 1, current + "1", result, '1');
        }
    }
    
    vector<string> findBinaryStrings(int n)
    {
        vector<string> result;
        generateStrings(n, n, n, "", result, ' ');
        return result;
    }
};
