class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        if(n == 0)  return 0;


        int ind = 0;
        for(ind = 0; ind<n; ind++) {
            if(s[ind] != ' ')
                break;
        }

        int sign = 1;
        if(ind<n) {
            if(s[ind] == '-')
                sign = -1;
            if(s[ind] == '-' || s[ind] == '+')
                ind++;
        }
        
        int res = 0;
        for(;ind<n; ind++) {
            if(s[ind]<'0' || s[ind]>'9')
                break;
            
            if( 1.0*res > (INT_MAX - int(s[ind]-'0'))/10.0 ) {
                if(sign == -1) 
                    return INT_MIN;
                else 
                    return INT_MAX;
            }
            res = res*10 + int(s[ind]-'0');
        }

        if(sign==-1)
            return -1*res;
        
        return res;
    }
};