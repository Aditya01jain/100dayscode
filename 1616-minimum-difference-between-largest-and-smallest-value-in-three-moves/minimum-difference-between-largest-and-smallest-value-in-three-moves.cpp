class Solution {
public:
    void solve(vector<int>& nums,int i,int j ,int c,int & mini){
        if(c==3){
            mini = min(mini,(nums[j]-nums[i]));
            return;
        }
        solve(nums,i+1,j,c+1,mini);
        solve(nums,i,j-1,c+1,mini);
        return;
    }
    int minDifference(vector<int>& nums) {
        if(nums.size()<=3){
            return 0;
        }
        int i =0;
        int j = nums.size()-1;
        int mini =INT_MAX;
        int c=0;
        sort(nums.begin(),nums.end());
        solve (nums,i,j,c,mini);
        return mini;
    }
};