vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int> dist(n, INT_MAX);
        
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            for(auto &it : adj[node]){
                if(it.second + cost < dist[it.first]){
                    dist[it.first]=it.second + cost;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        return dist;
    }
