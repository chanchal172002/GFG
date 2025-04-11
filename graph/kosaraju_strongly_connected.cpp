void dfs1(int node, vector<vector<int>>&adj, vector<int>&visit){
      visit[node]=1;
      for(int i=0;i<adj[node].size();i++){
          if(visit[adj[node][i]]==0){
              dfs1(adj[node][i], adj, visit);
          }
      }
  }
  
   void dfs2(int node, vector<vector<int>>&adj, vector<int>&visit, stack<int>&s){
      visit[node]=1;
      for(int i=0;i<adj[node].size();i++){
          if(visit[adj[node][i]]==0){
              dfs2(adj[node][i], adj, visit, s);
          }
      }
      s.push(node);
  }
  
    int kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<vector<int>>reverse_adj(n);
        for(int i=0;i<n;i++){
            for(int j=0; j< adj[i].size();j++){
                int u = adj[i][j];
                reverse_adj[u].push_back(i);
            }
        }
        vector<int>visit(n,0);
        stack<int>s;
        for(int i=0;i<n;i++){
                if(visit[i]==0){
                dfs2(i,adj,visit,s);
                
            }
        }
       fill(visit.begin(), visit.end(), 0);
        int count=0;
        for(int i=0;i<n;i++){
            int u = s.top();
            s.pop();
            if(visit[u]==0){
                dfs1(u,reverse_adj,visit);
                count++;
            }
        }
        return count;
    }
