class Solution
{
public:
    int minDeletions(string s)
    {

        int n = s.length();
        vector<int> hash(26, 0);

        for (int i = 0; i < n; i++)
        {
            hash[s[i] - 'a'] += 1;
        }

        sort(hash.begin(), hash.end(), greater<int>());

        int ans = 0;            // count of deletion
        int left = hash[0] - 1; // why -1 , becasuse for second itteration left limit has to decrease by 1 everytime or by val-1
        for (int i = 1; i < 26; i++)
        {

            int val = hash[i];

            if (val > left)
            { // val < left, no deletion
                if (left > 0)
                {
                    ans += val - left;
                }
                else
                {
                    ans += val;
                }
            }

            left = min(left - 1, val - 1);
        }

        return ans;
    }
};