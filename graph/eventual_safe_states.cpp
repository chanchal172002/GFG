 bool dfs(vector<int> adj[],int node, vector<int>&visit, vector<int>& path_visit, vector<int>& safe){
       visit[node]=1;
       path_visit[node]=1;
       
       for(auto i: adj[node]){
           if(visit[i]==0 && dfs(adj,i,visit,path_visit,safe)) return true;
           else if(visit[i]==1 && path_visit[i]==1) return true;
       }
       path_visit[node]=0;
       safe.push_back(node);
       return false;
   }
    
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int> visit(n,0);
         vector<int> path_visit(n,0);
         vector<int> safe;
        bool ans;
        for(int i =0;i<n;i++){
            if(visit[i]==0){
            ans= dfs(adj,i,visit,path_visit,safe);
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
