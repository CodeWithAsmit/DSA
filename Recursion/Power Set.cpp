/* Time :- O[n*(2^n)] Space :- O[n*(2^n)] */

class Solution 
{
    public:
    void solve(int curLength, string &tempString, string &mainString, vector<string>&result)
    {
        if(curLength==mainString.length())
        {
            result.push_back(tempString);
            return;
        }
        
        string newString = tempString + mainString[curLength];
        solve(curLength+1, tempString, mainString, result);
        solve(curLength+1, newString, mainString, result);
        return;
    }
    vector<string> AllPossibleStrings(string mainString)
    {
        string tempString="";
        vector<string>result;
        solve(0,tempString,mainString,result);
        sort(result.begin(),result.end());
        return result;
    }
};
