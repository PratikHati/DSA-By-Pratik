class Solution
{
public:
    int LIS(vector<int> &nums, int curr_index, int prev_index, vector<vector<int>> &dp)
    {

        if (curr_index == nums.size() - 1)
        {

            if (prev_index == -1 || nums[curr_index] > nums[prev_index])
            {
                return 1;
            }

            return 0;
        }

        if (dp[curr_index][prev_index + 1] != -1)
            return dp[curr_index][prev_index + 1];

        // do not take it
        int nt = LIS(nums, curr_index + 1, prev_index, dp);
        // take it

        int t = 0;
        if (prev_index == -1 || nums[curr_index] > nums[prev_index])
        {

            t = LIS(nums, curr_index + 1, curr_index, dp) + 1;
        }

        dp[curr_index][prev_index + 1] = max(t, nt);

        return dp[curr_index][prev_index + 1];
    }
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return LIS(nums, 0, -1, dp);
    }
};