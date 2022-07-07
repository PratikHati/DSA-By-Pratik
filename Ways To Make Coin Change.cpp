#include <bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));

    for (int i = 0; i <= value; i++)
    {
        if (i % denominations[0] == 0)
        {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= value; j++)
        {

            if (denominations[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - denominations[i]];
            }
        }
    }

    return dp[n - 1][value];
}