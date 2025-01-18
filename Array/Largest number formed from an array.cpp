/* Time :- O(NlogN) and Space :- O(N) */

class Solution
{
public:
    static bool comparator(int a,int b)
    {
        string ab = to_string(a) + to_string(b);
        string ba = to_string(b) + to_string(a);
        return ab > ba;
    }
    string largestNumber(vector<int>& nums)
    {
        string ans;
        int count = 0;
        sort(nums.begin(),nums.end(),comparator);

        for(auto it : nums)
        {
            if(it==0)
            {
                count++;
            }
            ans+=(to_string(it));
        }
        return count==nums.size() ? "0" : ans;
    }
};
