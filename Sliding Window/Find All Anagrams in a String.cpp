// Time Complexity: O(N + M), Space Complexity: O(N)
// Note: The space used by the hash map is O(26), which is considered constant.
// The O(N) space is due to the 'ans' vector.

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> pCount, windowCount;
        
        for (auto it : p)
        {
            pCount[it]++;
        }

        int i = 0;
        int j = 0;
        int window = p.length();
        vector<int>ans;

        while (j < s.length())
        {
            windowCount[s[j]]++;

            if (j - i + 1 == window)
            {
                if (windowCount == pCount)
                {
                    ans.push_back(i);
                }
            }
            else if(j - i + 1 > window)
            {
                windowCount[s[i]]--;
                if (windowCount[s[i]] == 0)
                {
                    windowCount.erase(s[i]);
                }
                i++;

                if (windowCount == pCount)
                {
                    ans.push_back(i);
                }
            }
            j++;
        }
        return ans;
    }
};
