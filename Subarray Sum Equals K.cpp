class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        int n = nums.size();

        vector<int> prefix_sum(n, 0);
        prefix_sum[0] = nums[0];

        for (int i = 1; i < n; i++)
        {

            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        unordered_map<int, int> um;
        int count = 0;
        um[0] = 1; // initialization

        for (int i = 0; i < n; i++)
        {

            int target = prefix_sum[i] - k;

            if (um[target] != 0)
            {
                count += um[target]; // important
            }

            um[prefix_sum[i]] += 1;
        }

        return count;
    }
};