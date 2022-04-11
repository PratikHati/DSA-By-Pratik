#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;
  //int level = -1;
  
  Edge(int src, int nbr)
  {
    this->src = src; 
    this->nbr = nbr;
    //this->level = -1;
  }
};

bool isBipartite(vector<vector<Edge>> &graph,vector<int> &v,int index,vector<bool> &b){

  queue<pair<int,int>> q;
  pair<int, int> p;
  p.first = index;
  p.second = 0;
  q.push(p);

  while(!q.empty()){
    pair<int,int> p2 = q.front();
    q.pop();
    //check condn

    if(b[p2.first] == true){        //already lvl exists
      if(v[p2.first] != p2.second){
        return false;
      }
    }
    else{
      v[p2.first] = p2.second;
      b[p2.first] = true;
    }

    
    int idx = p2.first;
    //visit all nbr
    for(int i=0;i<graph[idx].size();i++){
      int target = graph[idx][i].nbr;

      if(b[target] == false){
        
        pair<int ,int> temp;
        temp.first = target;
        temp.second = v[idx] +1; 

        q.push(temp);
      }
    }
  }

  return true;
}
int main() {                                                                        
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  

  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w; 
    cin >> u >> v >> w;
 
    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));

  } 
  
  vector<int> v(vtces,-1);
  vector<bool> b(vtces,false);
  bool ans = true;
  // write your code here
  for(int i=0;i<vtces;i++){

    if(b[i] == false){
      if(!isBipartite(graph,v,i,b)){
        ans = false;
        break;
      }
    }
  }

  if(ans){
    cout<<"true";
  }
  else{
    cout<<"false";
  }
   return 0;
}