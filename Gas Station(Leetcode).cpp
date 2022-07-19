class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        vector<int> sum(n, 0);
        int total = 0;

        for (int i = 0; i < n; i++)
        {
            sum[i] = gas[i] - cost[i];
            total += sum[i];
        }

        if (total < 0)
        {
            return -1;
        }

        total = 0;
        int pos = 0;
        for (int i = 0; i < n; i++)
        {

            total += sum[i];

            if (total < 0)
            { // hypothesis think..... no need to check for entire circle
                total = 0;
                pos = i + 1;
            }
        }

        return pos;
    }
};