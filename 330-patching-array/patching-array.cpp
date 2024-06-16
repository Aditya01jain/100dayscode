// Dhairya Kumar Singh

class Solution 
{
public:
    int minPatches(vector<int>& nums, int n) 
    {
        long long maxreach = 1;
        int i = 0;
        long count = 0;
        while(maxreach <= n)
        {
            if(i<nums.size() && maxreach >= nums[i])
            {
                maxreach += nums[i++];
            }else
            {
                count++;
                maxreach += maxreach;
            }
        }
        return count;
    }
};