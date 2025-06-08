/* Time :- O(Nlogm) Space :- O(1) */

int findSum(vector<int>& boards)
{
    int sum = 0;
    for(int length : boards)
    {
        sum += length;
    }
    return sum;
}
bool isValidPartition(vector<int>& boards, int k, int maxLength)
{
    int painters = 1;
    int currentSum = 0;

    for (int length : boards)
    {
        if (length > maxLength)
        {
            return false;
        }
        if (currentSum + length <= maxLength)
        {
            currentSum += length;
        }
        else
        {
            painters++;
            currentSum = length;
        }
    }
    return painters <= k;
}
int painter_partition(vector<int>& boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = findSum(boards);
    int result = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValidPartition(boards, k, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}
