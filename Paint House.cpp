#include <bits/stdc++.h>
using namespace std;
int Paint_House(vector<vector<int>> &cost, int size)
{
    vector<vector<int>> dp(3, vector<int>(size, 0));

    dp[0][0] = cost[0][0];
    dp[1][0] = cost[0][1];
    dp[2][0] = cost[0][2];

    for (int i = 1; i < size; i++)
    {
        dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + cost[i][0];

        dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + cost[i][1];

        dp[2][i] = min(dp[1][i - 1], dp[0][i - 1]) + cost[i][2];
    }

    return min(dp[0][size - 1], min(dp[1][size - 1], dp[2][size - 1]));
}
int main()
{

    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[i][0] = a;
        v[i][1] = b;
        v[i][2] = c;
    }
    cout << Paint_House(v, n);

    return 0;
}