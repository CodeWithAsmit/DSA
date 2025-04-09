/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        string temp = "";
        vector<string>words;

        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        
        if(pattern.length() == 1 && s.length() == 1)
        {
            return 1;
        }

        for(auto it : s)
        {
            if(it != ' ')
            {
                temp.push_back(it);
            }
            else
            {
                words.push_back(temp);
                temp="";
            }
        }

        if(temp.size() > 0)
        {
            words.push_back(temp);
        }

        if(pattern.length() != words.size())
        {
            return 0;
        }

        for(int i=0;i<pattern.size();i++)
        {
           bool possibility1 = mp1.find(pattern[i]) != mp1.end() && mp1[pattern[i]] != words[i];

           bool possibility2 = mp2.find(words[i]) != mp2.end() && mp2[words[i]] != pattern[i];

           if(possibility1 || possibility2)
           {
                return 0;
           }

           mp1[pattern[i]] = words[i];
           mp2[words[i]] = pattern[i];
        }
        return 1;
    }
};
