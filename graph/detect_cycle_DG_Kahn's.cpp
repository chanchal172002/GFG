 bool isCyclic(vector<vector<int>> &graph) {
        
         int n = graph.size();
        vector <int> indegree (n,0);
        queue <int> q;
        vector<int>ans;
        for(int i = 0; i < n; i++){
            for(auto j : graph[i]){
                indegree[j]++;
            }
        }
        for(int i = 0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int temp=0;
        while(!q.empty()){
            temp++;
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i : graph[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(temp==n) return false;
        return true;
    }
