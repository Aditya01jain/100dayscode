class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int,int> temp;
        for(int x:nums)
            temp[x]++;
        for(auto &pair:temp){
            if(pair.second==1)
                return (pair.first);
        }
        return -1;
    }
};