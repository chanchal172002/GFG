  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n,1e9));
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            adj[u][v]=adj[v][u]=it[2];
        }
        for(int i = 0;i<n;i++){
            adj[i][i]=0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k] + adj[k][j] < adj[i][j])
                        adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }

        int ans = INT_MAX;
        int index = INT_MAX;

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                if(adj[i][j]<= distanceThreshold) count++;
            }
            if(count <= ans){
                ans=count;
                index =i;
            }
        }
        return index;
    }
