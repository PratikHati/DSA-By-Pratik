#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int gbl = 1;

void KPartion(int n, int k, int level, int nes, vector<vector<int>> &ans)
{

    if (level > n)
    {
        if (nes == k)
        {
            cout << gbl << ". ";
            for (auto x : ans)
            {
                cout << "[";
                for (int y = 0; y < x.size(); y++)
                {
                    if (y == x.size() - 1)
                    {
                        cout << x[y];
                    }
                    else
                        cout << x[y] << ", ";
                }
                // for(auto y:x){
                //     if(y.size() == 1)
                //     cout<<y<<",";
                // }
                cout << "] ";
            }
            cout << endl;
            gbl++;
        }
        return;
    }

    for (int i = 0; i < k; i++)
    {
        if (ans[i].size() > 0)
        {

            ans[i].push_back(level);
            KPartion(n, k, level + 1, nes, ans);
            ans[i].pop_back();
        }
        else
        {
            ans[i].push_back(level);
            KPartion(n, k, level + 1, nes + 1, ans);
            ans[i].pop_back();
            break;
        }
    }

    return;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ans(k, vector<int>());
    // if(n ==0 || k==0){
    //     cout<<"0";
    //     return 0;
    // }

    // if(n==k || k==1){
    //     cout<<"1";
    //     return 0;

    // }

    if (n > k)
        KPartion(n, k, 1, 0, ans); // 1 is level, 0 is filed sets

    // else{
    //     cout<<"0";
    //     return 0;
    // }
    return 0;
}