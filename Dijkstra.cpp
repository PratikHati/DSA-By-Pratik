vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(V,INT_MAX);
        
        
        pq.push(make_pair(0,S));
        dist[S]=0;
        
        while(!pq.empty()){
            
            int distance = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            int neighbour = adj[node].size();       //length of entire 2D vector, not it's internal
            
            for(int i=0;i<neighbour;i++){
                
                int d =  adj[node].at(i).at(1);
                
                int n =  adj[node].at(i).at(0);
                
                if((d+distance) < dist[n]){
                    
                    dist[n] = d+distance;
                    
                    pq.push(make_pair(dist[n],n));
                }
            }
        }
        
        return dist;
    }