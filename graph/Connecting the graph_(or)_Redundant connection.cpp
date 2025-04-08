    int find_parent(int u, vector<int>&parent){
        if(u==parent[u]) return u;
        return parent[u]=find_parent(parent[u],parent);
    }
  
    int Solve(int n, vector<vector<int>>& edge) {
        vector<int>parent(n);
        vector<int>size(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
        
        int redundant_edges=0;
        for(int i=0; i<edge.size(); i++){
            int u = edge[i][0];
            int v = edge[i][1];
            int parent_u = find_parent(u,parent);
            int parent_v = find_parent(v,parent);
            if(parent_u==parent_v){
                redundant_edges++;
                continue;
            } 
            if(size[parent_u]>size[parent_v]){
                parent[parent_v] = parent_u;
                size[parent_u]+=size[parent_v];
            }else{
                parent[parent_u] = parent_v;
                size[parent_v]+=size[parent_u];
            }
        }
        
        int components=0;
        for(int i=0; i<n; i++){
            if(parent[i]==i) components++;
        }
        if(redundant_edges>= components-1) return components-1;
        return -1;
    }
