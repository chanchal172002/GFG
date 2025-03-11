  // using two visited arrays
 bool dfs(vector<vector<int>>& adj, int node, vector<int> &visit, vector<int>&path_visit){
        visit[node]=1;
        path_visit[node]=1;
        
        for(auto i : adj[node]){
            if(visit[i]==0 && dfs(adj, i, visit,path_visit)) return true;
            else{
                if(visit[i]==1 && path_visit[i]==1) return true;
            }
        }
        path_visit[node]=0;
        return false;
    }
    bool isCyclic(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> visit(n,0);
         vector<int> path_visit(n,0);
        
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                if(dfs(adj, i, visit, path_visit)) return true;
            }
        }
        return false;
    }
