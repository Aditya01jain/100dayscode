class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<n+1;i++){
            int sum = 0;
            int nums =i;
            while(nums!=0){
                sum+=nums%2;
                nums/=2;
            }
            res.push_back(sum);
        }
        return res;
        
    }
};