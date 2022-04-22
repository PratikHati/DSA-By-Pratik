#include<bits/stdc++.h>
using namespace std;

void GetMaxGoldMine(vector<vector<int>> &vec,vector<vector<bool>> &b,int i,int j,vector<int> &bag,int row,int col){

    if(i<0 || i>= row || j<0 || j>= col){
        return;
    }

    if(b[i][j]){
        return;
    }

    if(vec[i][j] == 0){
        return;
    }

    b[i][j] = true;
    bag.push_back(vec[i][j]);

    //right
    GetMaxGoldMine(vec,b,i,j+1,bag,row,col);
    //left
    GetMaxGoldMine(vec,b,i,j-1,bag,row,col);
    //up
    GetMaxGoldMine(vec,b,i-1,j,bag,row,col);
    //down
    GetMaxGoldMine(vec,b,i+1,j,bag,row,col);

    return;
}
int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> vec(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int d;
            cin>>d;

            vec[i][j] = d;
        }
    }

    // for(auto x: vec){
    //     for(auto y: x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<vector<bool>> b(n,vector<bool>(m,false));
    int maxans = INT_MIN;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            int ans = 0;
            if(vec[i][j] != 0 && b[i][j] == false){

                vector<int> bag; 
                GetMaxGoldMine(vec,b,i,j,bag,n,m);

                for(auto x: bag){
                    ans += x;
                }
                
                if(ans > maxans){
                    maxans = ans;
                }
            }

            
        }
    }

    cout<<maxans;
    return 0;
}