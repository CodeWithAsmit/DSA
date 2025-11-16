/* Approach 1 */

/* Time :- O(logn) Space :- O(logn) */

/* Accoring to problem we can do it as 2+3+2+3+2+3=6+9 or (n*k) means (23*3) = 69 */

int sumOfAllDigit(string mainString)
{
    int sum=0;
    for(char it : mainString)
    {
        sum = sum + it-'0';
    }
    return sum;
}

int solve(int sum, string mainString)
{
    if(sum<10)
    {
        return sum;
    }
    sum = sumOfAllDigit(mainString);    
    return solve(sum, to_string(sum));
}

int superDigit(string mainString, int k)
{
    long long sum = sumOfAllDigit(mainString);
    sum = sum * k;
    return solve(sum, to_string(sum));
}

/* Approach 2 --> Iterative */

long long int solve(long long int n)
{
    int sum = 0;
    while(n > 0 || sum > 9)
    {
        if(n == 0)
        {
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int superDigit(string n, int k)
{
	long long int sum=0;
	for(int i=0; i<n.size(); i++)
	{
	    sum = sum + n[i] - '0';
	}
	return solve(sum*k);
}

/* Approach 3 --> Most Efficient Approach */

long long int solve(long long int n)
{
    if (n == 0)
    {
	return 0;
    }
    return (n % 9 == 0) ? 9 : (n % 9);
}
int superDigit(string n, int k)
{
	long long int sum=0;
	for(int i=0; i<n.size(); i++)
	{
	    sum = sum + n[i] - '0';
	}
	return solve(sum*k);
}
