#include <iostream>
#include <vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector<string> getMazePaths(int sr, int sc, int dr, int dc)
{

    if (sr == dr && sc == dc)
    {
        vector<string> ans;
        ans.push_back("");

        return ans;
    }
    vector<string> curr;

    if (sc + 1 <= dc)
    {
        vector<string> ans1 = getMazePaths(sr, sc + 1, dr, dc);

        for (int i = 0; i < ans1.size(); i++)
        {
            curr.push_back("h" + ans1[i]);
        }
    }

    if (sr + 1 <= dr)
    {
        vector<string> ans2 = getMazePaths(sr + 1, sc, dr, dc);

        for (int i = 0; i < ans2.size(); i++)
        {
            curr.push_back("v" + ans2[i]);
        }
    }

    return curr;
}

void display(vector<string> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans = getMazePaths(0, 0, n - 1, m - 1);
    display(ans);

    return 0;
}