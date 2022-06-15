#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    // do xor ways
    int xxory = arr[0];
    for (int i = 1; i < n; i++)
    {
        xxory ^= arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        xxory ^= i;
    }

    int rightSetBit = xxory & ~(xxory - 1);

    int x = 0;
    int y = 0;

    // devide arr[i] into two buckets
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & rightSetBit)
        {
            x ^= arr[i];
        }
        else
        {
            y ^= arr[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i & rightSetBit)
        {
            x ^= i;
        }
        else
        {
            y ^= i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return make_pair(y, x);
        }
        else
        {
        }
    }

    return make_pair(x, y);
}
