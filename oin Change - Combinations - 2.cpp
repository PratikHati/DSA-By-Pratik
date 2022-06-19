#include <bits/stdc++.h>
using namespace std;
void coinChange(int i, vector<int> &coins, int amtsf, int tamt, string asf)
{
    // write your code here
    if (i == coins.size())
    {
        if (amtsf == tamt)
        {
            for (int i = 0; i < asf.size(); i++)
            {
                cout << asf[i] << "-";
            }
            cout << "." << endl;
        }
        return;
    }

    int count = (tamt - amtsf) / coins[i];

    for (int j = count; j >= 1; j--)
    {
        string str = "";
        for (int x = 1; x <= j; x++)
        {
            str += to_string(coins[i]);
        }

        coinChange(i + 1, coins, amtsf + (coins[i] * j), tamt, asf + str);
    }

    coinChange(i + 1, coins, amtsf, tamt, asf);
}
int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int amt;
    cin >> amt;
    string ans = "";
    coinChange(0, coins, 0, amt, ans);
}