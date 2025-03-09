class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>>q;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visit(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O' && visit[i][j]==0){
                    q.push({i,j});
                    visit[i][j]=1;
                }
            }
        }


        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(i+1<n && board[i+1][j]=='O'&& visit[i+1][j]==0){
                visit[i+1][j]=1;
                q.push({i+1,j});
            }
            if(j+1<m && board[i][j+1]=='O'&& visit[i][j+1]==0){
                visit[i][j+1]=1;
                q.push({i,j+1});
            }
            if(i-1>=0 && board[i-1][j]=='O'&& visit[i-1][j]==0){
                visit[i-1][j]=1;
                q.push({i-1,j});
            }
            if(j-1>=0 && board[i][j-1]=='O'&& visit[i][j-1]==0){
                visit[i][j-1]=1;
                q.push({i, j-1});
            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visit[i][j]==0){
                    board[i][j]='X';
                }
            }
           
        }
    }
};
