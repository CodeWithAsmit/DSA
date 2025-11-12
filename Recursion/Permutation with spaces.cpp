/* Time :- O[n*(2^n)] Space :- O[n*(2^n)] */

/* Solve function time complexity is O(N) beacuse of erase function and solve function is called O(2^n) times so overall time is --> O[n*(2^n)] */

class Solution
{
    public:
    void solve(int currLength, int totalLength, string tempString, string mainString, vector<string> &ans)
    {
        if(currLength==totalLength)
        {
            ans.push_back(tempString);
            return;
        }
        
        string tempAddChar = tempString + mainString[0];
        string tempAddSpace = tempString + ' ' + mainString[0];
        mainString.erase(0,1);
        
        solve(currLength + 1, totalLength, tempAddSpace, mainString, ans);
        solve(currLength + 1, totalLength, tempAddChar, mainString, ans);
        return;
    }
    
    vector<string> permutation(string mainString)
    {
        string tempString;
        vector<string>result;
        
        int length = mainString.length();   
        tempString.push_back(mainString[0]);
        
        mainString.erase(0,1);
        solve(1,length,tempString,mainString,result);
        return result;
    }
};

/* More optimal by removing erase function --> But still time and space is same as above */

class Solution
{
public:
    void solve(int index, int n, string tempString, const string &mainString, vector<string> &ans)
    {
        if (index == n)
        {
            ans.push_back(tempString);
            return;
        }
        
        solve(index + 1, n, tempString + " " + mainString[index], mainString, ans);
        solve(index + 1, n, tempString + mainString[index], mainString, ans);
    }

    vector<string> permutation(string mainString)
    {
        vector<string> result;
        
        if (mainString.empty())
        {
            return ans;
        }
        
        string tempString(1, mainString[0]);
        solve(1, mainString.size(), tempString, mainString, result);
        return result;
    }
};
