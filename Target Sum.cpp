int subsetsum(vector<int> &arr, int target, int n)
{

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    if (arr[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][0] = 1;
    }
    if (arr[0] != 0 && arr[0] <= target)
    {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (arr[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i]];
            }
        }
    }

    return dp[n - 1][target];
}
int targetSum(int n, int target, vector<int> &arr)
{
    // Write your code here.
    int sum = 0;
    for (auto x : arr)
    {
        sum += x;
    }

    if (sum - target < 0 || (sum - target) % 2)
    {
        return false;
    }

    return subsetsum(arr, (sum - target) / 2, n);
}
