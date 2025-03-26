    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<vector<int>>q;
        q.push({0,src,0});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int stop = top[0];
            int city = top[1];
            int price = top[2];
            if(stop > k) continue;
            for(auto &it : adj[city]){
                if(price+it.second < dist[it.first]){
                    dist[it.first]=price+it.second;
                    q.push({stop+1, it.first,dist[it.first]});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
