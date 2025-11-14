/* Time :- O(2^n) Space :- O(2^n) */

/* Refer To LUV Video for Time complexity analysis of any recursive function */

class Solution
{
public:
    void solve(int openLeftCnt, int closeLeftCnt, string &tempString, vector<string> &ansVector)
    {
        if(openLeftCnt == 0 && closeLeftCnt == 0)
        {
            ansVector.push_back(tempString);
            return;
        }

        if(openLeftCnt>0)
        {
            tempString = tempString + '(';
            solve(openLeftCnt - 1, closeLeftCnt, tempString, ansVector);
            tempString.pop_back();
        }
        
        if(openLeftCnt < closeLeftCnt)
        {
            if(closeLeftCnt>0)
            {
                tempString = tempString + ')';
                solve(openLeftCnt, closeLeftCnt - 1, tempString, ansVector);
                tempString.pop_back();
            }
        }
        return;
    }
    vector<string> generateParenthesis(int n)
    {
        string tempString="(";
        vector<string>ansVector;  
        solve(n-1,n,tempString,ansVector);
        return ansVector;
    }
};
