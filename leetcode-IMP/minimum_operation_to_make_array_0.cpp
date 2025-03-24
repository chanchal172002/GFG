long long sum (int n){
        if(n==0) return 0;
        int i=1;
        long long x=1;
        long long y=4;
        long long ans=0;
        while(true){
             if(y-1>n){
                ans+= (1LL *i*(n-x+1));
                return ans;
            }else ans+=(1LL *i*(y-x));
            x=y;
            y*=4;
            i++;
        }
        return ans;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long count= 0, ans=0;
        for(int i=0;i<queries.size();i++){
            int l= queries[i][0];
            int r =queries[i][1];
            count = sum(r)-sum(l-1);
            ans+=(count+1)/2;
        }
        return ans;
    }
