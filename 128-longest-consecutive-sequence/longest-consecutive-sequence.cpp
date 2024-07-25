class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans = 0;
        for(int i:s){
            if(!s.count(i-1)){
                int cur = i;
                int curs = 1;
                while(s.count(cur+1)){
                    cur = cur+1;
                    curs++;
                }
                ans = max(ans,curs);
            }
        }
        return ans;
    }
};