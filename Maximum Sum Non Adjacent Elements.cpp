#include <bits/stdc++.h>
#include <vector>

using namespace std;
int Maximum_Sum_Non_Adjacent_Elements(vector<int> &v, int size)
{

    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return v[0];
    }

    vector<vector<int>> dp(2, vector<int>(size, 0));

    dp[0][0] = v[0]; // include
    dp[1][0] = 0;    // dont include

    for (int i = 1; i < size; i++)
    {

        dp[0][i] = dp[1][i - 1] + v[i];
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
    }

    return max(dp[0][size - 1], dp[1][size - 1]);
}
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        int ans;
        cin >> ans;
        v[i] = ans;
    }

    cout << Maximum_Sum_Non_Adjacent_Elements(v, n);
}