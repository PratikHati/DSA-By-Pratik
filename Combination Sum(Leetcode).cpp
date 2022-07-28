class Solution
{
public:
    void Combination_Sum(vector<int> &candidates, int index, int n, int target, vector<int> &curr, vector<vector<int>> &ans)
    {

        if (target == 0 || index == n)
        {

            if (target == 0)
            {
                ans.push_back(curr);
            }

            return;
        }

        // if add it 1. add again and  not
        if (candidates[index] <= target)
        {

            curr.push_back(candidates[index]);

            Combination_Sum(candidates, index, n, target - candidates[index], curr, ans);

            curr.pop_back();
        }

        // do not add
        Combination_Sum(candidates, index + 1, n, target, curr, ans);

        return;
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> ans;
        vector<int> curr;
        int n = candidates.size();

        Combination_Sum(candidates, 0, n, target, curr, ans);

        return ans;
    }
};