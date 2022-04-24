#include <bits/stdc++.h>

using namespace std;

class Edge
{  
public:
  int src = 0; 
  int nbr = 0;

  Edge(int src, int nbr)
  {
    this->src = src; 
    this->nbr = nbr;

  }
};
void TopologicalOrder(vector<vector<Edge>> &graph,int curr, vector<bool> &b, stack<int> &ans){
  
  b[curr] = true;

  for(int i=0;i<graph[curr].size();i++){

    int child = graph[curr][i].nbr;

    if(b[child] == false){

      TopologicalOrder(graph,child,b,ans);
      
    }
  }

  ans.push(curr);
  return;
}
int main() {                                                                             
  
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  
  
  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {  
    int u, v;  
    cin >> u >> v;   
 
    graph[u].push_back(Edge(u, v)); 
  } 

  //write your code here  
  vector<bool> b(vtces,false);
  stack<int> ans;
  
  for(int i=0;i<vtces;i++){
    
    if(b[i] == false){
      
      TopologicalOrder(graph,i,b,ans);
    }
  }

  while(!ans.empty()){
    cout<<ans.top()<<endl;
    ans.pop();
  }
 
  return 0;
}