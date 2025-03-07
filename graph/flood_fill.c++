   vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {  
        if (image[sr][sc] == color) return image;   // if the starting pixel is colored, return
         queue<pair<int,int>>q;
        q.push({sr,sc});
        int prev_col= image[sr][sc];

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col]=color;
            if(row+1 < image.size() && image[row+1][col]==prev_col) q.push({row+1,col});
            if(col+1 < image[0].size() && image[row][col+1]==prev_col) q.push({row,col+1});
            if(row-1 >=0 && image[row-1][col]==prev_col) q.push({row-1,col});
            if(col-1 >=0 && image[row][col-1]==prev_col) q.push({row,col-1});
        }
        return image;
    }
