#include <bits/stdc++.h>
void SubsetSum(vector<int> &arr, int n, vector<vector<bool>> &dp, int sum)
{

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {

            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return;
}
int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write your code here.
    int sum = 0;
    for (auto x : arr)
    {
        sum += x;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    SubsetSum(arr, n, dp, sum);

    int mindiff = INT_MAX;
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i] == true)
        {

            int sum2 = sum - i;

            int diff = abs(sum2 - i);

            mindiff = min(mindiff, diff);
        }
    }

    return mindiff;
}
