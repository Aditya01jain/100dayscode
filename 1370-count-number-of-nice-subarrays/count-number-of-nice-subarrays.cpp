class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>um;
        int cnt = 0;
        int oddcnt = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2 ==1)
            {
                oddcnt++;
            }
            if(oddcnt == k)
            {
                cnt++;
            }
            if(um.find(oddcnt - k) != um.end())
            {
                cnt += um[oddcnt - k];
            }
            if(um.find(oddcnt)!=um.end())
            {
                um[oddcnt]++;
            }
            else{
                um[oddcnt] = 1;
            }
        }
        return cnt;
    }
};