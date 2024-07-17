class Solution {
public:
    bool solve(vector<int>& nums,int s,int e ,int target){
        int st = s;
        int en = e;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]<target){
                st=mid+1;
            }else{
                en =mid-1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int in =0;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i]==target) return true;
            if(nums[i]>nums[i+1]){
                in=i;
                break;
            }
        }
        return solve(nums,0,in,target) || solve(nums,in+1,nums.size()-1,target);
    }
};