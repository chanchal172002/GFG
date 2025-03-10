vector<vector<int>> bfs(vector<vector<int>>& grid, vector<vector<int>> &visit, int i, int j){
      vector<vector<int>> positions;
      positions.push_back({0,0});
      
      queue<pair<int, int>>q;
      q.push({i,j});
      
      while(!q.empty()){
          int row=q.front().first;
          int col=q.front().second;
          
          q.pop();
          
          if(row+1 < grid.size() &&grid[row+1][col]==1 && visit[row+1][col]==0){  // down
              positions.push_back({i-row-1, j-col});
              visit[row+1][col]=1;
              q.push({row+1,col});
          } 
            if(col+1 < grid[0].size() && grid[row][col+1]==1 && visit[row][col+1]==0){ //right
                q.push({row,col+1});
                 positions.push_back({i-row, j-col-1});
                visit[row][col+1]=1;
            }
            
            if(row-1 >=0 && grid[row-1][col]==1 && visit[row-1][col]==0){ //up
                q.push({row-1,col});
                positions.push_back({i-row+1, j-col});
                visit[row-1][col]=1;
            } 
            if(col-1 >=0 && grid[row][col-1]==1 &&  visit[row][col-1]==0){  // left
                q.push({row,col-1});
                 positions.push_back({i-row, j-col+1});
                visit[row][col-1]=1;
            } 
      }
      return positions;
  }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        set<vector<vector<int>>>ans;
        
        vector<vector<int>> visit(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visit[i][j]==0){
                    visit[i][j]=1;
                    vector<vector<int>> island= bfs(grid,visit,i,j);
                    
                    // cout<<island<<endl;
                    ans.insert(island);
                }
            }
        }
        return ans.size();
    }
