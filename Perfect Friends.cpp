#include<bits/stdc++.h>

using namespace std;

void GetConnected(vector<vector<int>> &graph,int i,vector<bool> &b,vector<int> &components){
  b[i] = true;
  components.push_back(i);

  //itterate all child nodes
  for(int j=0; j<graph[i].size(); j++){
    
    int child = graph[i][j];

    if(b[child] == false){
      //recursion
      GetConnected(graph,child,b,components);
    }
  }

  return;
}
int main(){
   int n;
   cin>>n;
      
   int k;
   cin>>k;
      
   // write your code here
  
   vector<vector<int>> graph(n,vector<int>());

   for(int i=0;i<k;i++){
     int a,b;

     cin>>a>>b;

     graph[a].push_back(b);
     graph[b].push_back(a);
   }

   vector<bool> b(n,false);

   vector<int> components;
   vector<vector<int>> mainans;

   for(int i=0;i<n;i++){

     if(b[i] == false){
       GetConnected(graph,i,b,components);

       mainans.push_back(components);
       
       components.clear();
     }
   }

  //  for(auto x: mainans){
  //    for(auto y: x){
  //      cout<<y<<" ";
  //    }
  //    cout<<endl;
  //  }

   int ans = 0;
   int size = mainans.size();

   for(int i=0;i<size;i++){
     for(int j=i+1;j<size;j++){

       int x = mainans[i].size();
       int y = mainans[j].size();

       ans += (x*y);  //permutation
     }
   }
   
   cout<<ans<<endl;
   return 0;
 }