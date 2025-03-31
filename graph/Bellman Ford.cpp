/*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
     vector <int> dist(V,1e8);
     int n= edges.size();
     dist[S]=0;
     for(int i=0;i<V-1;i++){
         
         for(int j=0;j<n;j++){
             int u= edges[j][0];
             int v= edges[j][1];
             int w= edges[j][2];
             if(dist[u]!=1e8 && dist[u]+w <dist[v]){
                 dist[v]=dist[u]+w;
             }
         }
     }
     
      for(int i=0;i<V;i++){
         
         for(int j=0;j<n;j++){
             int u= edges[j][0];
             int v= edges[j][1];
             int w= edges[j][2];
             if(dist[u]!=1e8 && dist[u]+w <dist[v]){
                 return {-1};
             }
         }
     }
     
     return dist;
    }
