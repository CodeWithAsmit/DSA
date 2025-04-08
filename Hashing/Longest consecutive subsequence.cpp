/* Approach 1 :- Brute Force */

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        int ans = 0;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        for(int i = 0; i < nums.size(); i++)
        {
            mp1[nums[i]] = i;
        }

        for(auto it : mp1)
        {
            int num = it.first;

            if(mp2.find(num) != mp2.end())
            {
                continue;
            }

            int temp = num;
            int count = 1;

            while(mp1.find(temp - 1) != mp1.end())
            {
                temp--;
                if(mp2.find(temp) != mp2.end())
                {
                    count += mp2[temp];
                    break;
                }
                count++;
            }

            mp2[num] = count;
            ans = max(ans, count);
        }
        return ans;
    }
};

/* Approach 2 :- Most Optimal Approach --> By memorising more efficiently and productive for next number */

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        int ans = 0;
        unordered_map<int, int> mp1; 
        unordered_map<int, int> mp2;
        
        for(int i = 0; i < nums.size(); i++)
        {
            mp1[nums[i]] = i;
        }

        for (auto it : mp1)
        {
            int num = it.first;

            if (mp2.find(num) != mp2.end()) 
            {
                continue;
            }

            int curr = num;
            int count = 0;

            vector<int> memorise;

            while (mp1.find(curr) != mp1.end() && mp2.find(curr) == mp2.end())
            {
                memorise.push_back(curr);
                curr--;
                count++;
            }

            if (mp2.find(curr) != mp2.end())
            {
                count += mp2[curr];
            }

            for (int i = 0; i < memorise.size(); ++i)
            {
                mp2[memorise[i]] = count - i;
            }
            
            ans = max(ans, count);
        }
        return ans;
    }
};
