    int check_diff(string s1, string s2){
        
        int n= s1.length();
        int diff=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) diff++;
        }
        return diff;
    }

    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        set <string> s;
        for(auto &str : wordList){
            s.insert(str);
        }
        queue<pair<string,int>>q;
        q.push({startWord, 1});
        while(!q.empty()){
            string word = q.front().first;
            int dist = q.front().second;
            q.pop();
            s.erase(word);
            if(word==targetWord) return dist;
            for(auto &i : s){
                if(check_diff(i,word)==1){
                    q.push({i,dist+1});
                }
            }
        }
    return 0;
    }
