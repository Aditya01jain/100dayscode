#include <bits/stdc++.h>


int solvmemo(vector<int> &nums){
    int n=nums.size();
    if(n==1){
        return nums[0];
    }
    vector<int> dp1(n,0);
    dp1[0]=0;
    for(int i=1;i<n;i++){
        int inc=dp1[i-2]+nums[i];
        int exc=dp1[i-1]+0;
        dp1[i]=max(inc,exc);
    }
    return dp1[n-1];

}
int maximumNonAdjacentSum(vector<int> &nums){
    int ans = solvmemo(nums);
    return ans;
}