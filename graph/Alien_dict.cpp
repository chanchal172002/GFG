vector<char>first_distinct(string a, string b){
       int n=min(a.length(), b.length());
       for(int i=0;i<n;i++){
           if(a[i]!=b[i]) return{a[i],b[i]};
       }
       if(a.length()>b.length()) return {};
       return {'X'};
   }
  
    string findOrder(vector<string> &words) {
        vector<int> indegree(26,0);
        unordered_map<char,set<char>>m;
        set<char>unique;
        string ans="";
        for(auto &i : words){
            unique.insert(i.begin(),i.end());
        }
        for(int i=0;i<words.size()-1;i++){
            vector<char> temp = first_distinct(words[i],words[i+1]);
            if(temp.empty()) return "";
            if(temp[0]=='X') continue;
            if(m[temp[0]].find(temp[1])==m[temp[0]].end()){
                m[temp[0]].insert(temp[1]);
                indegree[temp[1]-'a']++;
            }
            
        }
        queue<int>q;
        for(auto &i : unique){
            if(indegree[i-'a']==0) q.push(i);
        }
        while(!q.empty()){
            char node = q.front();
            q.pop();
            ans+=node;
            for(auto i : m[node]){
                indegree[i-'a']--;
                if(indegree[i-'a']==0) q.push(i);
            }
        }
        if(ans.length()==unique.size()) return ans;
        return "";
    }
