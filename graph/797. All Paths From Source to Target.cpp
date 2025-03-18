void dfs(vector<vector<int>>&graph, vector<int> &temp, int src, int dest, vector<vector<int>> &ans){
        temp.push_back(src);
       if(src==dest){
        ans.push_back(temp);
       }else{
        for(auto child : graph[src]){
            dfs(graph, temp, child,dest, ans);
        }
       }

       temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src =0 ;
        int destination = graph.size()-1;
        vector<vector<int>>ans;
        vector<int>temp;
        
        dfs(graph,temp, 0, destination,ans);
        return ans;
    }
