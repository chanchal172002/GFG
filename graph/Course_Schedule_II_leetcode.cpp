vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        if(prerequisites.empty()){
            for(int i=0;i<numCourses; i++){
                ans.push_back(i);
            }
            return ans;
        }
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        queue <int> q;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
         for(int i = 0; i < numCourses; i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }
        for(int i=0; i< numCourses; i++){
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
            for(auto i : adj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(temp==numCourses) return ans;
        return {};
    }
