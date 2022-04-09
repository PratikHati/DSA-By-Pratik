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

  Edge(int src, int nbr)
  {
    this->src = src; 
    this->nbr = nbr;
  }
};

bool BFS(int index, vector<vector<Edge>> &graph, vector<bool> &b){

  queue<string> q;
  string str = to_string(index);
  q.push(str);

  while(!q.empty()){
    string curr = q.front();
    q.pop();

    int n = curr.length();
    int val = curr[n-1] - 48;

    if(b[val] == true){
      return true;
    }

    b[val] = true;
    //visit all nbr
    for(int i=0;i<graph[val].size();i++){

      int data = graph[val][i].nbr;

      if(b[data] == false){
         
        char cdata = data + 48;

        q.push(curr+cdata); 
      }
    }
  }

  return false;
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
  
  vector<bool> b(vtces,false);
 // write your code here 
 bool ans = false;
  for(int i=0;i<vtces;i++){
    if(b[i] == false){
      
      if(BFS(i,graph,b))
        ans = true;
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
