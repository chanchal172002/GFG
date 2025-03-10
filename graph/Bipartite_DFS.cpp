bool  dfs(vector<vector<int>>&adj, int node, vector<int>&visit, int color ){
        visit[node] = color;
        
        for(auto child : adj[node]){
            if(visit[child]==-1 && !dfs(adj, child, visit, 1-color)){
                return false;
            }else if(visit[child]==color) return false;
            
        }
        return true;
    }
  
    bool isBipartite(vector<vector<int>>& adj) {
      //color 0&1
      int n = adj.size();
      vector<int>visit (n,-1);

      for(int i=0;i<n;i++){
          if(visit[i]==-1 && !dfs(adj,i,visit,0)){
              return false;
          }
      }
      return true;
    }
