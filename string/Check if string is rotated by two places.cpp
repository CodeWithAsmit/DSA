/* Time and Space :- O(N) */

class Solution
{
public:
    bool isRotated(string& s1, string& s2)
    {
        if (s1.length() != s2.length()) return false;
        if (s1.length() <= 2) return s1 == s2;
    
        int n = s1.length();
    
        string clockwise = s1.substr(2) + s1.substr(0, 2);
        string anticlockwise = s1.substr(n - 2) + s1.substr(0, n - 2);
        return s2 == clockwise || s2 == anticlockwise;
    }
};

/* Time :- O(N) and Space :- O(1) */

class Solution
{
public:
    bool isRotated(string& s1, string& s2)
    {
        int n = s1.length();
        if (n != s2.length()) return false;
        if (n <= 2) return s1 == s2;

        bool clockwise = true;
        for (int i = 0; i < n; ++i)
        {
            if (s1[(i + 2) % n] != s2[i])
            {
                clockwise = false;
                break;
            }
        }
    
        bool anticlockwise = true;
        for (int i = 0; i < n; ++i)
        {
            if (s1[(i - 2 + n) % n] != s2[i])
            {
                anticlockwise = false;
                break;
            }
        }
        return clockwise || anticlockwise;
    }
};
