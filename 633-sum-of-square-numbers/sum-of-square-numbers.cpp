class Solution {
public:
    bool judgeSquareSum(int c) {


        for(int a = 0 ; a <= sqrt(c) ; a++){

            int bsquare = (c - (a*a));

            if(ceil(sqrt(bsquare)) == floor(sqrt(bsquare)))
                return true;
        }
        return false;
        
    }
};