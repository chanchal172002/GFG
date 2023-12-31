PROBLEM LINK :
https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

vector<vector<int> > fourSum(vector<int> &arr, int x) {
        int n= arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
       for(int i=0;i<n-1;i++){
           if(i>0 && arr[i-1]==arr[i]) continue;
           for(int j=i+1;j<n;j++){
              if(j>i+1 && arr[j-1]==arr[j]) continue;
               int l=j+1;
               int k=n-1;
               while(l<k){
                   int sum=arr[i]+arr[j]+arr[k]+arr[l];
                   if(sum<x)l++;
                  else if(sum>x)k--;
                   else{
                       ans.push_back({arr[i],arr[j],arr[l],arr[k]});
                       l++; k--;
                       while(l<k && arr[l-1]==arr[l]) l++;
                       while(l<k && arr[k+1]==arr[k]) k--;
                   }
               }
           }
       }
        
    return ans;}

Time Complexity : O(N3)
Space Complexity : O(N)
