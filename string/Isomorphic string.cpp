/* Time :- O(N) Space :- O(26) ie. Constant */

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char,char>map1;
        unordered_map<char,char>map2;

        if (s.length() != t.length())
        {
            return 0;
        }         

        for(int i=0;i<s.length();i++)
        {
            bool possiblity1 = map1.find(s[i]) != map1.end() && map1[s[i]] != t[i];
            bool possiblity2 = map2.find(t[i]) != map2.end() && map2[t[i]] != s[i]; 

            if(possiblity1 || possiblity2)
            {
                return 0;
            }      
            map1[s[i]] = t[i];
            map2[t[i]] = s[i];
        }
        return 1;
    }
};
