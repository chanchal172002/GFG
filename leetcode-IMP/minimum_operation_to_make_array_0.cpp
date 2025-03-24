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

------------****************************--------------------
question link : https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/

Explaination :
If you are given an array [2,3,4,6,7,1] and you can choose 2 element at once and decrease them by 1, find minimum operation to make all elements 0

case 1: 
Everytime we will be making a decrement of 2 from the total sum
so, total sum = 2+3+4+6+7+1 = 23
23-2 = 21, 21-2=19, 19-2=17, 17-2=15, 15-2=13, 13-2=11, 11-2=9, 9-2=7, 7-2=5, 5-2=3, 3-2=1, 1-1=0
total operation = 12
which is ceil(23/2) = ceil(11.5) = 12

case 2:
[1,1,100]
here total sum = 102, so ans should ideally be ceil(102/2) i.e 51
but it is incorrect 
why?
we will decrease 1->0 100->99, 1->0, 99->98, then 98 times -1
so total operation is 100

in the case when total_sum - max_element < max_element , ans is max_element




