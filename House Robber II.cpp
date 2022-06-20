long long int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    if (nums.size() == 0)
    {
        return 0;
    }
    if (nums.size() == 1)
    {
        return nums[0];
    }
    vector<vector<long long int>> dp(2, vector<long long int>(nums.size(), 0));

    dp[0][0] = nums[0];
    dp[1][0] = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        dp[0][i] = dp[1][i - 1] + nums[i];
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1]);
    }

    return max(dp[0][nums.size() - 1], dp[1][nums.size() - 1]);
}
long long int houseRobber(vector<int> &valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if (n == 1)
    {
        return valueInHouse[0];
    }
    vector<int> dpl;
    vector<int> dpr;

    for (int i = 0; i < n; i++)
    {
        int d = valueInHouse[i];
        if (i != 0)
        {
            dpr.push_back(d);
        }
        if (i != n - 1)
        {
            dpl.push_back(d);
        }
    }

    return max(maximumNonAdjacentSum(dpl), maximumNonAdjacentSum(dpr));
}