#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int Count_Encodings(string str)
{
    if (str.length() == 1)
    {

        return 1;
    }

    vector<int> dp(str.length() + 1, 0);
    dp[0] = 1;

    for (int i = 1; i < str.length(); i++)
    {

        // 1.
        if (str[i] == '0' && str[i - 1] == '0')
        {
            dp[i] = 0;
        }

        // 2.
        else if (str[i] == '0' && str[i - 1] != '0')
        {
            if (str[i - 1] < '3')
            {
                if (i - 2 >= 0)
                    dp[i] = dp[i - 2];
                else
                    dp[i] += 1; // very imprtant
            }

            else
            {
                dp[i] = 0;
            }
        }

        else if (str[i] != '0' && str[i - 1] == '0')
        {
            dp[i] = dp[i - 1];
        }

        else
        {

            dp[i] = dp[i - 1];

            if (str[i - 1] <= '2' && str[i] <= '6')
            {
                if (i - 2 >= 0)
                    dp[i] += dp[i - 2];
                else
                    dp[i] += 1;
            }
        }
    }

    return dp[str.length() - 1];
}
int main()
{
    string str;
    cin >> str;

    if (str[0] != '0')
    {
        cout << Count_Encodings(str);
    }

    return 0;
}