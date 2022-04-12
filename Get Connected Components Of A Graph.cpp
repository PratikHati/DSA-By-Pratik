#include<bits/stdc++.h>
using namespace std;
   class Edge {
       public:
          int src;
          int nbr;
          int wt;

      Edge(int src, int nbr, int wt){
         this->src = src;
         this->nbr = nbr;
         this->wt = wt;
      }
   };
   
void GetConnectedComponenet(vector<Edge> graph[],int vtces,int edges,vector<int> &comps,vector<bool> &b,int source){
    
    
    b[source] = true;        
    comps.push_back(source);    //add to source
    for(auto x : graph[source]) //itterate over all nbr
    {
        if(b[x.nbr] == false)
            GetConnectedComponenet(graph,vtces,edges,comps,b,x.nbr);
    }
    return;
}

   int main(){
      int vtces;
      cin>>vtces;
      vector<Edge>graph[vtces];

      int edges;
      cin>>edges;
      for(int i = 0; i < edges; i++){
         int v1 ;
         int v2 ;
         int wt ;
         cin>>v1>>v2>>wt;
         graph[v1].push_back( Edge(v1, v2, wt));
         graph[v2].push_back( Edge(v2, v1, wt));
      }

      
       vector<vector<int>> comps;
       vector<bool> b(vtces,false);
       vector<int> temp;
      // write your code here
        for(int j=0;j<vtces;j++){
            if(b[j] == false)
            {
                GetConnectedComponenet(graph,vtces,edges,temp,b,j);
                comps.push_back(temp);
                temp.clear();
            }
                
        }
            
   
        cout<<"[";
        for(int i = 0 ; i<comps.size() ; i++){
            cout<<"[";
            for(int j = 0 ; j<comps[i].size() ; j++){
                if(j!=comps[i].size()-1)
                    cout<<comps[i][j]<<", ";
                else
                    cout<<comps[i][j];

            }
            cout<<"]";
            if(i!=comps.size()-1)cout<<", ";
        }
        cout<<"]";
    }