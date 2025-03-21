 bool dfs(vector<int> adj[],int node, vector<int>&visit, vector<int>& path_visit, vector<int>& safe){
       visit[node]=1;
       path_visit[node]=1;
       
       for(auto i: adj[node]){
           if(visit[i]==0 && dfs(adj,i,visit,path_visit,safe)) return true;
           else if(visit[i]==1 && path_visit[i]==1) return true;
       }
       path_visit[node]=0;
       safe.push_back(node);
       return false;
   }
    
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int> visit(n,0);
         vector<int> path_visit(n,0);
         vector<int> safe;
        bool ans;
        for(int i =0;i<n;i++){
            if(visit[i]==0){
            ans= dfs(adj,i,visit,path_visit,safe);
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }


//using BFS & graph reversal technique as we need outdegree

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> outdegree (n,0);
        vector<vector<int>>reverse_graph(n);
        for(int i=0;i<n;i++){
            for(auto &j : graph[i]){
                reverse_graph[j].push_back(i);

            }
        }
        vector<int>safe;
        queue <int> q;
        for(int i = 0; i < n; i++){
            outdegree[i]=graph[i].size();
        }
        for(int i = 0; i<n; i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &i : reverse_graph[node]){
                outdegree[i]--;
                if(outdegree[i]==0){
                    q.push(i);
                }
            }
        }
    for(int i=0;i<n;i++){
        if(outdegree[i]==0) safe.push_back(i);
    }
    return safe;
    }
