#include <bits/stdc++.h>
using namespace std;
bool exists(string str, vector<string> &v)
{

    for (int i = 0; i < v.size(); i++)
    {

        if (str.compare(v[i]) == 0)
            return true;
    }

    return false;
}
void Wordbreak(vector<string> &v, string target, vector<string> &ans)
{

    if (target.length() == 0)
    {

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;

        return;
    }
    for (int i = 1; i <= target.length(); i++)
    {

        string str = target.substr(0, i);

        if (exists(str, v))
        {

            string newtarget = target.substr(i);

            ans.push_back(str);

            Wordbreak(v, newtarget, ans);

            ans.pop_back();
        }
    }

    return;
}
int main()
{

    int n;
    cin >> n;

    vector<string> v(n);

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        v[i] = str;
    }

    vector<string> ans;
    string target;
    cin >> target;

    Wordbreak(v, target, ans);
}