#include <bits/stdc++.h> 
int sove(vector<int> &num, int x,vector<int>& dp){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans=sove(num,x-num[i]);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);
        }
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    vector<int> dp[num+1];
    for(int i=0;i<=num;i++){
        dp[i]=-1;
    }
    int ans=sove(num,x,dp);
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}
