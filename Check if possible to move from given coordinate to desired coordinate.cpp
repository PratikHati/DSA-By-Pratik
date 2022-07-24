//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int gcd(int a, int b)
    {

        if (a == 0 || b == 0)
        { // imp
            return 0;
        }
        if (a == b)
        {
            return a;
        }

        if (a > b)
        {
            return gcd(a - b, b);
        }

        return gcd(a, b - a);
    }
    int isPossible(int x, int y, int a, int b)
    {
        // code here
        x = abs(x);
        y = abs(y);
        a = abs(a);
        b = abs(b);

        if (gcd(a, b) == gcd(x, y))
        {
            return true;
        }

        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, a, b;

        cin >> x >> y >> a >> b;

        Solution ob;
        cout << ob.isPossible(x, y, a, b) << endl;
    }
    return 0;
}
// } Driver Code Ends