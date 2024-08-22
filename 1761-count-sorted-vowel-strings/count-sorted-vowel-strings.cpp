class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dict(5, 1);
        if(n == 0){
            return 0;
        }else{
            for(int i = 1; i <n; ++i){
                dict[0] = dict[0] + dict[1] + dict[2] + dict[3] + dict[4];
                dict[1] = dict[1] + dict[2] + dict[3] + dict[4];
                dict[2] = dict[2] + dict[3] + dict[4];
                dict[3] = dict[3] + dict[4];
                dict[4] = dict[4];
            }
        }
        return dict[0] + dict[1] + dict[2] + dict[3] + dict[4];

    }
};