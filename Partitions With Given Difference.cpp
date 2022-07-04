int SubsetCount(int n, vector<int> &arr, int target)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= target)
    {
        dp[0][arr[0]] = 1;
    }

    int mod = 1000000007;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (arr[i] > j)
            {
                dp[i][j] = dp[i - 1][j] % mod;
            }
            else
            {
                dp[i][j] = ((dp[i - 1][j] % mod) + (dp[i - 1][j - arr[i]] % mod)) % mod;
            }
        }
    }

    return dp[n - 1][target] % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int sum = 0;
    for (auto x : arr)
    {
        sum += x;
    }
    if (sum - d < 0 || (sum - d) % 2)
    {
        return false;
    }

    int target = (sum - d) / 2;

    return SubsetCount(n, arr, target);
}
