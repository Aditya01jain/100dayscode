class Solution {
public:
    int countCompleteDayPairs(vector<int>& h) {
        int n = h.size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((h[i]+h[j])%24==0){
                    c++;
                }
            }
        }
        return c;
    }
};