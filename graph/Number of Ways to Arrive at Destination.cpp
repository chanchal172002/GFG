int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>>adj(n);
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        ways[0]=1;
        dist[0]=0;
        int MOD = 1e9+7;
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
             adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int city = it[1];
            long long time = it[0];
            for(auto &i : adj[city]){
                int adj_city = i.first;
                long long adj_time = i.second;
                long long new_time = time+adj_time;
                if(dist[adj_city]==new_time){
                    ways[adj_city] = (ways[adj_city]+ways[city])%MOD; 
                }
                else if(new_time < dist[adj_city]){
                    dist[adj_city]=new_time;
                    ways[adj_city]=ways[city];
                    pq.push({new_time,adj_city});
                }
            }
        }
        return ways[n-1]%MOD;
    }
