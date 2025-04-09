int find_parent(int u, vector<int>&parent){
        if( parent[u] == u ) return u;
        return parent[u] = find_parent( parent[u], parent);
    }
  
    int union_by_size(int u, int v, vector<int>&size, vector<int>&parent){
        int parent_u = find_parent(u,parent);
        int parent_v = find_parent(v,parent);
        int ans=0;
        if(parent_u == parent_v)return size[parent_u];
        if(size[parent_u] > size[parent_v]){
            parent[parent_v] = parent_u;
            size[parent_u]+=size[parent_v];
            ans =  size[parent_u];
        }else{
            parent[parent_u] = parent_v;
            size[parent_v]+=size[parent_u];
            ans = size[parent_v];
        }
        return ans;
    }
  
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>parent(n*n);
        vector<int>size(n*n,1);
        for(int i = 0; i < n*n; i++){
            parent[i]=i;
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0 ,1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int u = i*n+j;
                if(grid[i][j]==1){
                    for(int k = 0; k < 4; k++){
                        int new_row = i+dr[k];
                        int new_col = j+dc[k];
                        if(new_row>=0 && new_row<n && new_col>=0 && new_col<n && grid[new_row][new_col]==1){
                            int v = (new_row*n)+new_col;
                            int temp = union_by_size(u,v,size,parent);
                        }
                    }
                }
            }
        }
        int ans = *max_element(size.begin(), size.end());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                 int u = i*n+j;
                 int temp=1;
                 set<int>s;
                if(grid[i][j]==0){
                    for(int k = 0; k < 4; k++){
                        int new_row = i+dr[k];
                        int new_col = j+dc[k];
                        if(new_row>=0 && new_row<n && new_col>=0 && new_col<n && grid[new_row][new_col]==1){
                            int v = (new_row*n)+new_col;
                            int parent_v = find_parent(v,parent);
                            if(s.count(parent_v)==0){
                                temp+=size[parent_v];
                                s.insert(parent_v);
                            }
                        }
                    }
                }
                ans = max(ans,temp);
            }
        }
        return ans;
    }
