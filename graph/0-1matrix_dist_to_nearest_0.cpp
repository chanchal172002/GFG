// need to use the direction matrix 
// instead of calling 4 if(s)
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m = mat[0].size();
        vector<vector<int>> visit(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<vector<int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    visit[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            vector<int> temp = q.front();
            q.pop();
            int i= temp[0];
            int j=temp[1];
            ans[i][j]=temp[2];

            if(i+1<n && visit[i+1][j]==0){
                visit[i+1][j]=1;
                q.push({i+1,j,temp[2]+1});
            }
             if(j+1<m && visit[i][j+1]==0){
                 visit[i][j+1]=1;
                q.push({i,j+1,temp[2]+1});
            }
             if(i-1>=0 && visit[i-1][j]==0){
                 visit[i-1][j]=1;
                q.push({i-1,j,temp[2]+1});
            }
             if(j-1>=0 && visit[i][j-1]==0){
                 visit[i][j-1]=1;
                q.push({i,j-1,temp[2]+1});
            }
        }
        return ans;
    }
