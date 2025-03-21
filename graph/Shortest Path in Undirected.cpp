  vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> visit(n,0);
        vector<int> ans(n,-1);
        
        queue<int> q;
        q.push(src);
        ans[src]=0;
        while(!q.empty()){
            int node = q.front();
            visit[node]=1;
            q.pop();
            for(auto i : adj[node]){
                if(visit[i]==0){
                    visit[i]=1;
                    ans[i]=ans[node]+1;
                    q.push(i);
                }
            }
        }
        return ans;
    }
