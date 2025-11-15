/* Time :- O(2^n) Space :- O[n*(2^n)] */

class Solution
{
  public:
    void solve(int oneLeftCnt, int zeroLeftCnt, int totalLength, string &tempString, vector<string> &ansVector)
    {
        if(tempString.length()==totalLength)
        {
            ansVector.push_back(tempString);
            return;
        }

        if(oneLeftCnt>0)
        {
            tempString = tempString + '1';
            solve(oneLeftCnt - 1, zeroLeftCnt, totalLength, tempString, ansVector);
            tempString.pop_back();
        }
        
        if(oneLeftCnt < zeroLeftCnt)
        {
            if(zeroLeftCnt>0)
            {
                tempString = tempString + '0';
                solve(oneLeftCnt, zeroLeftCnt - 1, totalLength, tempString, ansVector);
                tempString.pop_back();
            }
        }
        return;
    }
    vector<string> NBitBinary(int n)
    {
        string tempString="1";
        vector<string>ansVector;  
        solve(n-1,n,n,tempString,ansVector);
        return ansVector;
    }
};
