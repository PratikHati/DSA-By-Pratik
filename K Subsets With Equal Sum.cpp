#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
void KSubsetEqualSum(vector<int> &given, int n, int k, int level, int set, vector<vector<int>> &ans)
{

    if (level == n)
    {

        if (set == k)
        {

            int actual_sum = 0;

            for (auto x : ans[0])
            {
                actual_sum += x;
            }

            for (auto x : ans)
            {

                int sum = 0;
                for (auto y : x)
                {

                    sum += y;
                }

                if (sum != actual_sum)
                {
                    return;
                }
            }

            for (auto x : ans)
            {

                cout << "[";

                for (int i = 0; i < x.size(); i++)
                {

                    if (i == x.size() - 1)
                        cout << x[i];
                    else
                    {
                        cout << x[i] << ", ";
                    }
                }
                cout << "] ";
            }

            cout << endl;
        }
        return;
    }
    for (int i = 0; i < k; i++)
    {
        if (ans[i].size() > 0)
        {

            ans[i].push_back(given[level]);

            KSubsetEqualSum(given, n, k, level + 1, set, ans);

            ans[i].pop_back();
        }
        else
        {

            ans[i].push_back(given[level]);

            KSubsetEqualSum(given, n, k, level + 1, set + 1, ans);

            ans[i].pop_back();

            break;
        }
    }

    return;
}
int main()
{
    int n;
    cin >> n;

    vector<int> given;

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        given.push_back(d);
    }

    int k;
    cin >> k;

    vector<vector<int>> ans(k, vector<int>());

    KSubsetEqualSum(given, n, k, 0, 0, ans);
    return 0;
}