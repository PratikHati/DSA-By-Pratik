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

void BFS(vector<vector<Edge>> &graph, vector<bool> &b, int source){
  // b[src] = true;
  // ans.push_back(src);

  // cout<<src<<"@";
  // for(auto x: ans){
  //   cout<<x;
  // }
  // cout<<endl;

  queue<string> q;
  string s = to_string(source);
  q.push(s);
  

  //visit all neighbour
  while(!q.empty()){

    string str = q.front();
    q.pop();

    int size = str.length();
    int val = str[size-1] - 48;

    if(b[val] == true){
      continue;
    }

    b[val] = true;
 
    cout<<val<<"@";
    for(auto x : str){
      cout<<x;
    }
    cout<<endl;

      //visit all nbr
    for(int i=0;i<graph[val].size();i++){

      int neighbour = graph[val][i].nbr;
        
      if(b[neighbour] == false){

        char c = neighbour +48;
        string snew = str+ c;
        
        q.push(snew);
      }
    }

  }
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
  
  int src; 
  cin >> src;

  // write your code here     
  vector<bool> b(vtces,false);
  
  BFS(graph,b,src);
  return 0;
}