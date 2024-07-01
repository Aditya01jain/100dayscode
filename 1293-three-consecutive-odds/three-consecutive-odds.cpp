class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int c = 0;
        for(auto i : arr){
            i%2?++c:c=0;
            if(c==3) return true;
        }
        return false;
    }
};