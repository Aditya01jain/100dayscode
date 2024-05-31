class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int> m;
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(const auto& pair:m){
            if(pair.second==1){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};