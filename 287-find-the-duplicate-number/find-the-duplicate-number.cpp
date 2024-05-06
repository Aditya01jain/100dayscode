class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> ans;
        for(int i=0;i<nums.size();i++){
            ans[nums[i]]++;
            if(ans[nums[i]]>1){
                return nums[i];
            }
        }
        return -1;
    }
};