int find_parent(int u, vector<int>&parent){
        if(parent[u]==u)return u;
        return parent[u]=find_parent(parent[u],parent);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int>parent(n);
        vector<int>size(n,1);
        for(int i = 0; i < n; i++ ){
            parent[i]=i;
        }
        map<string, int>m;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(m.find(accounts[i][j])!=m.end()){
                    int u = find_parent(m[accounts[i][j]], parent);
                    int v = find_parent(i,parent);
                    if(u==v) continue;
                    if(size[u]<size[v]){
                        parent[u] = parent[v];
                        size[v]+=size[u];
                    }else{
                        parent[v]=parent[u];
                        size[u]+=size[v];
                    }
                }
                m[accounts[i][j]]=i;
            }
        }
        for(int i = 0; i < n; i++) cout<<parent[i]<<endl;
        vector<set<string>>ans(n);
        for(int i = 0; i < n; i++){
            int p = find_parent(i,parent);
            for(int j=1; j<accounts[i].size(); j++){
                ans[p].insert(accounts[i][j]);
            }
        }
        vector<vector<string>>final_ans;
        for(int i=0;i<n;i++){
            if(ans[i].empty())continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(), ans[i].begin(), ans[i].end()); 
            sort(temp.begin() + 1, temp.end());
            final_ans.push_back(temp);
        }
        return final_ans;
    }
