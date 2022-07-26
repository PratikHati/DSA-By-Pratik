class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();
        if (n == 1)
        {
            if (amount % coins[0] == 0)
            {
                return amount / coins[0];
            }

            return -1;
        }
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for (int i = 1; i <= amount; i++)
        {

            dp[0][i] = INT_MAX;
        }

        for (int i = 1; i <= n; i++)
        {

            for (int j = 0; j <= amount; j++)
            {

                if (coins[i - 1] <= j)
                {

                    if (dp[i][j - coins[i - 1]] != INT_MAX)
                        dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                    else
                        dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int ans = dp[n][amount];
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};