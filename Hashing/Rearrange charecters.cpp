/* Time:- O(Nlogn) Space :- O(26) */

/*General hashing approach*/

class Solution
{
    public:
    char maxCount(int hash[])
    {
        int max=-1;
        char temp;
        for(int i=0;i<26;i++)
        {
            if(hash[i]>max)
            {
                max=hash[i];
                temp=i+'a';
            }
        }
        return temp;
    }
    string rearrangeString(string str)
    {
        int hash[26]={0};
        int count=str.size();
        for(int i=0;i<str.length();i++)
        {
            hash[str[i]-'a']++;
        }
        char maxEle=maxCount(hash);
        int maxFre=hash[maxEle-'a'];
        if(maxFre>(count+1)/2)
        {
            return "-1";
        }
        int idx=0;
        string ans(count,' ');
        while(maxFre--)
        {
            ans[idx]=maxEle;
            idx+=2;
            hash[maxEle-'a']--;
        }
        
        for(int i=0;i<26;i++)
        {
            while(hash[i]>0)
            {
                idx=(idx>=count)?1:idx;
                ans[idx]=i+'a';
                idx+=2;
                hash[i]--;
            }
        }
        return ans; 
    }
};

/* Heap Approach, Time :- O(nlogn) and Space :- O(n) */

class Solution
{
public:
    struct Compare
    {
        bool operator()(const pair<int, char>& a, const pair<int, char>& b)
        {
            if (a.first == b.first)
            {
                return a.second > b.second;  
            }
            return a.first < b.first;
        }
    };
    string reorganizeString(string s)
    {
        string ans = "";
        unordered_map<char,int>mp;
        priority_queue<pair<int, char>, vector<pair<int, char>>, Compare> maxHeap;

        for(auto it : s)
        {
            mp[it]++;
        }

        for(auto it : mp)
        {
            maxHeap.push({it.second,it.first});
        }

        while(maxHeap.size()>1)
        {
            int count1 = maxHeap.top().first;
            char Char1 = maxHeap.top().second;
            maxHeap.pop();

            int count2 = maxHeap.top().first;
            char Char2 = maxHeap.top().second;
            maxHeap.pop();

            ans.push_back(Char1);
            ans.push_back(Char2);
            
            if(count1>1)
            {
                maxHeap.push({--count1,Char1});
            }
            if(count2>1)
            {
                maxHeap.push({--count2,Char2});
            }
        }

        if(maxHeap.size())
        {
            if(maxHeap.size()==1 and maxHeap.top().first ==1)
            {
                ans.push_back(maxHeap.top().second);
            }
            else
            {
                return "";
            }
        }
        return ans;
    }
};
