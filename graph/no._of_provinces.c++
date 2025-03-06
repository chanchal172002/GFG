void dfs(vector<vector<int>>& adj, int node, vector<int> &visited ){
        visited[node]=1;

        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i]==1 && visited[i]==0){
                dfs(adj,i, visited);
            }
        }
    }
int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> visited(n,0);
        int component=0;
        for(int i=0;i<n;i++){
            if (visited[i]==0){
                component++;
                dfs(adj,i,visited);
            }
        }
        return component;
    }
