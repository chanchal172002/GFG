// using BFS,
// push all the rotten oranges in the queue with a {-1,-1} to keep track of timing
// when we meet {-1,-1} means now we are moving to next minute for rotting the oranges

int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        q.push({-1,-1});
        int ans=0;

        while(!q.empty()){

            if(q.front().first==-1){
                q.pop();
                if(!q.empty()){
                    q.push({-1,-1});
                    ans++;
                }
                continue;
            }
         int i= q.front().first;
         int j=q.front().second;
         q.pop();
        if(i+1 < n && grid[i+1][j]==1){
            grid[i+1][j]=2;
            fresh--;
            q.push({i+1,j});
        } 
        if(j+1 < m && grid[i][j+1]==1){
            grid[i][j+1]=2;
             fresh--;
            q.push({i,j+1});
        } 
        if(i-1>=0 && grid[i-1][j]==1){
            grid[i-1][j]=2;
             fresh--;
            q.push({i-1,j});
        } 
         if(j-1>=0 && grid[i][j-1]==1){
            grid[i][j-1]=2;
             fresh--;
            q.push({i,j-1});
        }
        
        }

        if(fresh!=0)return -1;
        return ans;
    }
