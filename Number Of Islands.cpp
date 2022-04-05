#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
void MarkIsland(vector<vector<int>> &arr,vector<vector<bool>> &b,int i,int j){


    if(i <= -1 || i >= arr.size() || j <= -1 || j >= arr[0].size()){
        return;
    }

    if(arr[i][j] == 1 || b[i][j] == true){
        return;
    }

    b[i][j] = true;
    MarkIsland(arr,b,i+1,j);
    MarkIsland(arr,b,i-1,j);
    MarkIsland(arr,b,i,j-1);
    MarkIsland(arr,b,i,j+1);

    return;

}
int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> arr;

    for (int i = 0; i < n; i++)
    {
        vector<int> ans;
        for (int j = 0; j < m; j++)
        {
            int res;
            cin >> res;
            ans.push_back(res);
        }
        arr.push_back(ans);
    }

    //write your code here
    vector<vector<bool>> b(n,vector<bool>(m,false));
    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0 && b[i][j] == false){
                MarkIsland(arr,b,i,j);
                ans++;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}