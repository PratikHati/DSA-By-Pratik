class Solution
{
public:
    bool isPalindrom(string str)
    {

        for (int i = 0; i < str.length() / 2; i++)
        {

            if (str[i] != str[str.length() - i - 1])
            {
                return false;
            }
        }

        return true;
    }
    void getPalindromicPartition(string given, vector<string> &curr, vector<vector<string>> &allans)
    {

        if (given.size() == 0)
        {
            allans.push_back(curr);
            return;
        }

        for (int i = 0; i < given.size(); i++)
        {

            string temp = given.substr(0, i + 1);

            if (isPalindrom(temp))
            {

                curr.push_back(temp);

                getPalindromicPartition(given.substr(i + 1), curr, allans);

                curr.pop_back();
            }
        }

        return;
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> allans;
        vector<string> curr;

        getPalindromicPartition(s, curr, allans);

        return allans;
    }
};