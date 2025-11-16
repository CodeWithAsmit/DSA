/* Time :- O(N) Space :- O(1) */

/* Time Complexity analysis :- https://assets.leetcode.com/users/images/c65ae1a8-521b-44b4-bfe1-bd360ff64907_1657449403.9865541.jpeg */ 

/* T(N) = T(N-1) + 1 */

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if(n==1 || k==1)
        {
            return 0;
        }

        int totalDigit = pow(2,n-1);
        int mid = totalDigit/2;

        if(k<=mid)
        {
            return kthGrammar(n-1,k);
        }
        else
        {
            return !kthGrammar(n-1,k-mid);
        }    
    }
};
