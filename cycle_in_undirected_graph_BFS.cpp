 bool helper(int V, vector <int> adj[],int src, vector <int>&vis){
      vis[src]=1;
      queue<pair<int,int>> q;
      q.push({src,-1});
      
      while(!q.empty()){
          int node= q.front().first;
          int parent = q.front().second;
          q.pop();
          for(int i=0;i<adj[node].size();i++){
              if(vis[adj[node][i]]==0){
                  vis[adj[node][i]]=1;
                  q.push({adj[node][i],node});
              }
              else if(parent!=adj[node][i]) return true;
          }
     
          
      }
       return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
         vector <int> vis(V,0);
         
         for(int i=0;i<V;i++){
             if(vis[i]==0){
                 if(helper(V,adj,i,vis)) return true;
             }
         }
       return false;
    }
