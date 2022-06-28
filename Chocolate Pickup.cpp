#include <bits/stdc++.h>
int recursiveMaxi(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
{

    if (j1 < 0 || j1 >= c)
    {
        return INT_MIN;
    }

    if (j2 < 0 || j2 >= c)
    {
        return INT_MIN;
    }

    if (i == r - 1)
    { // last row
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }

    int maxi = INT_MIN;
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {

            // important
            int val = 0;
            if (j1 == j2)
            {
                val = grid[i][j1];
            }
            else
            {
                val = grid[i][j1] + grid[i][j2];
            }

            val += recursiveMaxi(i + 1, j1 + x, j2 + y, r, c, grid);

            maxi = max(maxi, val);
        }
    }

    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    // initialization
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == j)
                dp[r - 1][i][j] = grid[r - 1][j];
            else
                dp[r - 1][i][j] = grid[r - 1][i] + grid[r - 1][j];
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j = 0; j < c; j++)
        { // Alice
            for (int k = 0; k < c; k++)
            { // Bob
                int maxi = INT_MIN;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {

                        // important
                        int val = 0;
                        if (j == k)
                        {
                            val = grid[i][j];
                        }
                        else
                        {
                            val = grid[i][j] + grid[i][k];
                        }

                        if (!(j + x < 0 || j + x >= c || k + y < 0 || k + y >= c))
                            val += dp[i + 1][j + x][k + y];
                        maxi = max(maxi, val);
                    }
                }

                dp[i][j][k] = maxi;
            }
        }
    }

    return dp[0][0][c - 1];
}