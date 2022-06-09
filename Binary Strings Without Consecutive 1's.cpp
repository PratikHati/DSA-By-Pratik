int numberOfBinaryStrings(int n)
{
    // Write your code here.
    vector<int> v_0(n + 1, 0);
    vector<int> v_1(n + 1, 0);
    int m = 1000000007;

    v_0[1] = 1;
    v_1[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        v_0[i] = ((v_0[i - 1]) % m + (v_1[i - 1]) % m) % m;
        v_1[i] = (v_0[i - 1]) % m;
    }

    return ((v_0[n]) % m + (v_1[n]) % m) % m;
}
