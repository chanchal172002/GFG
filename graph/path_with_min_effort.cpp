const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, -1, 0, 1};
  
    int MinimumEffort(int r, int c, vector<vector<int>> &arr) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>>effort(r,vector<int>(c,INT_MAX));
        effort[0][0] = 0;
        pq.push({0,0,0});
        while(!pq.empty()){
            int x = pq.top()[1];
            int y = pq.top()[2];
            int diff = pq.top()[0];
            pq.pop();
            if(x==r-1 && y==c-1) return effort[x][y];
            for(int i = 0; i < 4; i++){
                int newr = x+dr[i];
                int newc = y+dc[i];
                if(newr >= 0 && newr < r && newc >= 0 && newc < c){
                    int new_diff = max(diff ,abs(arr[x][y]-arr[newr][newc]));
                    if(new_diff < effort[newr][newc]){
                        effort[newr][newc] = new_diff;
                        pq.push({effort[newr][newc], newr, newc});
                    }
                }
            }
        }
        return 0;
    }
