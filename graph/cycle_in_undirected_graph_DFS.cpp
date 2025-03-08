bool dfs (vector<vector<int>>& adj, int src, int parent, vector<int>& visit){
        
        visit[src]=1;
        
        for(auto neighbor : adj[src]){
            if(visit[neighbor] == 0){
               if(dfs(adj,neighbor, src, visit)) return true;
            }
            else if(visit[neighbor]==1 && neighbor!=parent) return true;
        }
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
      int n= adj.size();
      vector<int> visit(n,0);
      
      for(int i=0;i<n;i++){
          if(visit[i]==0){
              bool ans= dfs(adj, i, -1, visit);
              if(ans) return true;
          }
      }
      return false;
    }
