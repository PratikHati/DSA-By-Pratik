class Solution
{
public:
    //     int DSMemo(string s, string t,int sn,int tn, vector<vector<int>> dp){

    //         if(tn == -1){   //j
    //             return 1;
    //         }

    //         if(sn == -1){   //i

    //             return 0;
    //         }

    //         int m = (int)1e9+7;

    //         if(dp[sn][tn] != -1){
    //             return dp[sn][tn];
    //         }

    //         if(s[sn] == t[tn]){
    //             int a = DS(s,t,sn-1,tn,dp);;

    //             int b = DS(s,t,sn-1,tn-1,dp);

    //             dp[sn][tn] = ((a%m)+(b%m))%m;
    //         }
    //         else{
    //             dp[sn][tn] = (DS(s,t,sn-1,tn,dp))%m;
    //         }

    //         return dp[sn][tn];
    //     }

    int DSTable(string s, string t, int r, int c, vector<vector<int>> &dp)
    {
        // base
        for (int i = 0; i <= c; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 0; i <= r; i++)
        {
            dp[i][0] = 1;
        }

        int m = (int)1e9 + 7;

        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {

                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = ((dp[i - 1][j] % m) + (dp[i - 1][j - 1] % m)) % m;
                }
                else
                    dp[i][j] = dp[i - 1][j] % m;
            }
        }

        return dp[r][c];
    }

    int numDistinct(string s, string t)
    {

        int sn = s.length();
        int tn = t.length();
        vector<vector<int>> dp(sn + 1, vector<int>(tn + 1, 0));
        int m = (int)1e9 + 7;

        return (DSTable(s, t, sn, tn, dp)) % m;
    }
};