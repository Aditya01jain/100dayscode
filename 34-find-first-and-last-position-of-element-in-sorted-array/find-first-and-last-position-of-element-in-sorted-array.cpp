class Solution {
public:
    int first(vector<int>& nums,int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2; 
            if(nums[mid]==target){
                e=mid-1;
                ans =mid;
            }else if(nums[mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
    
    int last(vector<int>& nums,int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2; 
            if(nums[mid]==target){
                s=mid+1;
                ans =mid;
            }else if(nums[mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target),last(nums,target)};
    }
};