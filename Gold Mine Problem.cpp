//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int GetMax(vector<vector<int>> &M, int r, int c)
    {

        int row = M.size();
        int col = M[0].size();

        if (r < 0 || c < 0 || r >= row || c >= col)
        {
            return 0;
        }

        int up = 0;
        if (r - 1 >= 0)
        {
            up = M[r - 1][c + 1];
        }

        int down = 0;
        if (r + 1 < row)
        {
            down = M[r + 1][c + 1];
        }

        int curr = M[r][c + 1];

        return max(up, max(down, curr));
    }
    int maxGold(int n, int m, vector<vector<int>> &M)
    {
        // code here
        for (int i = m - 2; i >= 0; i--)
        { // col

            for (int j = 0; j < n; j++)
            { // row

                M[j][i] += GetMax(M, j, i);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, M[i][0]);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
}
// } Driver Code Ends