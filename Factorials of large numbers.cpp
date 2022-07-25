//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getIndex(vector<int> &ans, int index, int val)
    {

        int carry = 0;
        for (int i = 0; i < index; i++)
        {

            int temp = (val * ans[i]) + carry;

            ans[i] = temp % 10;

            carry = temp / 10;
        }

        while (carry)
        {
            ans[index] = carry % 10;
            carry /= 10;
            index++;
        }

        return index;
    }
    vector<int> factorial(int N)
    {
        // code here
        vector<int> ans(1000000);
        ans[0] = 1;
        int index = 1;

        for (int i = 2; i <= N; i++)
        {
            index = getIndex(ans, index, i);
        }

        vector<int> actual;
        for (int i = index - 1; i >= 0; i--)
        {
            actual.push_back(ans[i]);
        }

        return actual;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends