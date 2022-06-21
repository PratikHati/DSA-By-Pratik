#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> get_stair_paths(int n)
{
    // Write your code here
    if (n == 0)
    {
        vector<string> ans;
        ans.push_back("");

        return ans;
    }
    vector<string> ans;

    for (int i = 1; i <= 3; i++)
    {

        if (n - i >= 0)
        {
            vector<string> temp = get_stair_paths(n - i);

            for (int j = 0; j < temp.size(); j++)
            {
                ans.push_back(to_string(i) + temp[j]);
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans = get_stair_paths(n);
    int cnt = 0;

    cout << '[';
    for (string str : ans)
    {
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}