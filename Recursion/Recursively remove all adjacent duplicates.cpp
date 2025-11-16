/* Using Recursion Time :- O(N) Space :- O(N) + O(N) Aux Stack Space */

class Solution
{
public:
    void solve(string &mainString, string &resultantString)
    {
        if(mainString.length()==0)
        {
            return;
        }

        if(!resultantString.empty() && (mainString[0]==resultantString.back()))
        {
            resultantString.pop_back();
        }
        else
        {
            resultantString.push_back(mainString[0]);
        }
        mainString.erase(0,1);
        solve(mainString, resultantString);
    }
    string removeDuplicates(string mainString)
    {
        string resultantString;
        resultantString.push_back(mainString[0]);
        mainString.erase(0,1);
        solve(mainString, resultantString);
        return resultantString;
    }
};

/* Using Itrative Time :- O(N) Space :- O(N) */

class Solution
{
public:
    string removeDuplicates(string mainString)
    {
        string result;
        for (char it : mainString)
        {
            if (!result.empty() && result.back() == it)
            {
                result.pop_back();
            }
            else
            {
                result.push_back(it);
            }
        }
        return result;
    }
};
