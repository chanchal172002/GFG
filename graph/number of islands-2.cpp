int find_parent(int u, vector<int>&parent){
      if(parent[u]==u) return u;
      return parent[u]= find_parent(parent[u],parent);
  }
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &queries) {
        vector<int>parent(n*m);
        vector<int>size(n*m,1);
        vector<int>visit(n*m,0);
        for(int i=0;i<n*m;i++){
                parent[i] = i;
        }
        int s = queries.size();
        vector<int>ans(s,0);
        int count=0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for(int i=0;i<s;i++){
            int row = queries[i][0];
            int col = queries[i][1];
            int u = (row * m) + col;
            if(visit[u]==0){
            visit[u]=1;
            count++;
            for(int j=0;j<4;j++){
                int new_row = row+dr[j];
                int new_col = col+dc[j];
                int v = (new_row * m) + new_col;
                if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && visit[v]==1){
                    // cout<<u<<" "<<v<<endl;
                    int parent_u = find_parent(u,parent);
                    int parent_v = find_parent(v,parent);
                    if(parent_u == parent_v){
                        continue;
                    }
                    else{
                        count--;
                        if(size[parent_u]>size[parent_v]){
                            parent[parent_v]=parent_u;
                            size[parent_u]+=size[parent_v];
                        }else{
                            parent[parent_u]=parent_v;
                            size[parent_v]+=size[parent_u];
                        }
                    }
                }
            }
            }
            ans[i]=count;
        }
        return ans;
    }
