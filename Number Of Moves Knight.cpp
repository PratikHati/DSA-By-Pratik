#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int findMinPath(int n,int i,int j,int x,int y){
    vector<vector<bool>> matrix(n, vector<bool>(n,false));
    matrix[i][j] = true;
    int dx[] = {-2,-2,1,2,-2,-1,1,2};
    int dy[] = {-1,-2,-2,-1,1,2,2,1};

    queue<pair<int,pair<int,int>>> q;
    pair<int,pair<int,int>> p1;
    pair<int,int> p2;

    p2.first = i;
    p2.second = j;
    p1.first = 0;
    p1.second = p2;

    q.push(p1);

    while(q.empty()){
        pair<int,pair<int,int>> p3;
        p3 = q.front();
        q.pop();
        int dist = p3.first;
        int src = p3.second.first;
        int des = p3.second.second;

        for(int i=0;i<8;i++){
            int x = src+dx[i];
            int y = des+dx[i];


            if(idPossible())
        }
    }
}
int main()
{
    int i,j;
    cin>>i>>j;

    int x,y;
    cin>>x>>y;

    cout<<findMinPath(9,i,j,x,y);//9 is chess board size
    return 0;
}