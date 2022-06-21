int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    if (n == 0)
    {
        return 0;
    }
    vector<vector<int>> dp(3, vector<int>(n, 0));

    // for 1st day
    dp[0][0] = points[0][0];
    dp[1][0] = points[0][1];
    dp[2][0] = points[0][2];

    for (int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + points[i][0];
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + points[i][1];
        dp[2][i] = max(dp[1][i - 1], dp[0][i - 1]) + points[i][2];
    }

    return max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1]));
}