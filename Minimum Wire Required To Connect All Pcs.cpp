#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{  
public:
  int src = 0; 
  int nbr = 0;
  int wt = 0;

  Edge(int src, int nbr, int wt)
  {
    this->src = src; 
    this->nbr = nbr;
    this->wt = wt;
  }
};


struct CompareHeight {
    bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        // if(p1.first == p2.first){

        //   string s1 = p1.second;
        //   string s2 = p2.second;

        //   char c1 = s1[s1.length()-1];
        //   char c2 = s1[s2.length()-1];


        //   if(c1 == c2){
        //     return p1.second.length() > p2.second.length();
        //   }

        //   return c1 < c2;
        // }
        return p1.first > p2.first;
    }
};


void PrimesMST(vector<vector<Edge>>& graph, int curr, vector<bool>& bv) {

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, CompareHeight> pq;

    //------------------weight,curr,prev------------------------

    pair<int, pair<int, int>> p1;
    pair<int, int> p2;

    p2.first = 0;   //prev
    p2.second = -1;  //now

    p1.first = 0;
    p1.second = p2;

    pq.push(p1);

    while (!pq.empty()) {

        pair<int, pair<int, int>> now = pq.top();
        pq.pop();

        int a = now.first;  //weight
        int b = now.second.first; //curr
        int c = now.second.second;  //prev

        if (bv[b]== true) {
            continue;
        }

        bv[b] = true;

        if (c != -1)
            cout <<"[" <<b << "-" << c << "@" << a<<"]" << endl;

        for (int i = 0; i < graph[b].size(); i++) {

            int child = graph[b][i].nbr;
            int val = graph[b][i].wt;

            if (bv[child] == false) {

                pair<int, pair<int, int>> nei;
                pair<int, int> x;

                x.first = child;
                x.second = b;

                nei.first = val;
                nei.second = x;

                pq.push(nei);
            }
        }

    }

    return;
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
 
    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));

  }   

  //write your code here
  vector<bool> b(vtces,false);  
  PrimesMST(graph,0,b);
  
  return 0;
}