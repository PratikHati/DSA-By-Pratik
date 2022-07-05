#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void pattern_matching(string s1, string s2, vector<string> &hash, string pattern)
{

    if (s2.length() == 0)
    {
        if (s1.length() == 0)
        {

            vector<bool> track(26, false);

            for (int i = 0; i < pattern.length(); i++)
            {

                if (track[pattern[i] - 97] == false)
                {

                    track[pattern[i] - 97] = true;

                    cout << pattern[i] << " -> " << hash[pattern[i] - 97] << ", ";
                }
            }

            cout << "." << endl;
        }
        return;
    }

    int index = s2[0] - 97;

    string news2 = s2.substr(1);

    if (hash[index].length() != 0)
    {

        string hashed = hash[index];

        int size = hashed.length();

        string currs1 = s1.substr(0, size);

        if (hash[index].compare(currs1) == 0)
        {

            string rests1 = s1.substr(size);

            pattern_matching(rests1, news2, hash, pattern);
        }
    }
    else
    {

        for (int i = 1; i <= s1.size(); i++)
        {

            string str = s1.substr(0, i);

            hash[index] = str;

            string news1 = s1.substr(i);

            pattern_matching(news1, news2, hash, pattern);

            hash[index] = "";
        }
    }

    return;
}
int main()
{

    string s1;
    string s2;

    cin >> s1;

    cin >> s2;

    vector<string> hash(26, "");

    int start = 0;

    int n = s2.size();

    pattern_matching(s1, s2, hash, s2);
}