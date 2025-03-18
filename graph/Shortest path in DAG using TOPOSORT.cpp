 void topo_sort (vector<vector<pair<int,int>>>&adj,vector<int>&visit,int node, vector<int>&topo){
       visit[node]=1;
       
       for(auto i : adj[node]){
           if(visit[i.first]==0){
               topo_sort(adj, visit, i.first, topo);
           }
       }
       topo.push_back(node);
   }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto i : edges ){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> visit(V,0);
        vector<int> topo;
         for( int i=0;i<V;i++){
             if(visit[i]==0){
                 topo_sort(adj,visit,i,topo);
             }
         }
        reverse(topo.begin(), topo.end());
        vector<int> ans(V,INT_MAX);
        int i=0;
        while(topo[i]!=0){
            ans[topo[i]]=-1;
            i++;
         }
        ans[0]=0;
        
        while(i<topo.size()){
            int node = topo[i];
            for(auto child : adj[node]){
                ans[child.first] = min(ans[child.first], ans[node]+child.second);
            }
            i++;
        }
        return ans;
    }
