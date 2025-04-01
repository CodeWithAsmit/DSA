/* Time :- O(N*K) Space :- O(N) */

void printMap(unordered_map<char,int>&mp)
{
    for(auto it : mp)
    {
        cout<<it.first<<"  "<<it.second<<"\n";
    }
}

bool verifyBothWord(string &word, string &pattern)
{
    unordered_map<char,char>mp;
    
    for(int i=0;i<pattern.size();i++)
    {
        if(mp.find(pattern[i])==mp.end())
        {
            mp[pattern[i]] = word[i];
        }
        else
        {
            if(mp[pattern[i]] != word[i])
            {
                return 0;
            }
        }
    } 
    return 1;
}

vector<string> findMatchedWords(int n, vector<string> dict, string pattern)
{
    vector<string>ans;
    
    for(auto it : dict)
    {
        if(it.length() == pattern.length())
        {
            if (verifyBothWord(it,pattern))
            {
                ans.push_back(it);
            }
        }
    }
    return ans;
}
