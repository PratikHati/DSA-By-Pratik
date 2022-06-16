class Solution
{
public:
    int maximumSwap(int num)
    {
        // rightmost max

        vector<int> number;
        while (num)
        {
            number.push_back(num % 10);
            num /= 10;
        }

        reverse(number.begin(), number.end());

        int n = number.size();
        int maxright = n - 1;

        vector<int> hash(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            if (number[i] > number[maxright])
            {
                maxright = i;
            }

            hash[i] = maxright;
        }

        for (int i = 0; i < n; i++)
        {
            if (number[i] != number[hash[i]])
            {

                swap(number[i], number[hash[i]]);
                break;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans * 10 + number[i];
        }

        return ans;
    }
};