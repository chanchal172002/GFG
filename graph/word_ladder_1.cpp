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


//GETTING TLE IN LEETCODE

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        for(auto &str : wordList) s.insert(str);
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            string str = q.front().first;
            int dist = q.front().second;
            q.pop();
            s.erase(str);
            if(str==endWord)return dist;
            for(int i=0;i<str.length();i++){
                char original = str[i];
                for(char j ='a'; j<='z';j++){
                    if(j==original) continue;
                    else{
                        str[i]=j;
                        if(s.find(str)!=s.end()){
                            q.push({str,dist+1});
                        }
                    }
                }
                str[i]=original;
            }
        }
        return 0;
    }
