bool SubsetSum(vector<int> &arr, int n, int sum)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, false));

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
            {
                // do not include
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // both include and not include
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][sum];
}
bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int sum = 0;
    for (auto x : arr)
    {
        sum += x;
    }

    if (sum & 1)
        return false;
    return SubsetSum(arr, n, sum / 2);
}
