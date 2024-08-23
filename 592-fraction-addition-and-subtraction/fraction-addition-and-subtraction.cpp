class Solution {
    int GCDFinder(int a, int b){
        if(b == 0){
            return abs(a);
        }
        return GCDFinder(b, a%b);
    }

    int LCMFinder(int a, int b){
        int gcd = GCDFinder(a, b);
        
        return abs(a*b)/gcd;
    }


public:
    string fractionAddition(string expression) {
        vector<int> nus, dis;
        int i = 0;
        int n = expression.size();

        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') sign = -1;
                i++;
            }

            int numerator = 0;
            while (i < n && isdigit(expression[i])) {
                numerator = numerator * 10 + (expression[i] - '0');
                i++;
            }
            numerator *= sign;

            i++; // skip the '/'

            int denominator = 0;
            while (i < n && isdigit(expression[i])) {
                denominator = denominator * 10 + (expression[i] - '0');
                i++;
            }

            nus.push_back(numerator);
            dis.push_back(denominator);
        }

        int dino = dis[0];
        for(int i = 1; i < dis.size(); i++){
            // cout<<nus[i]<<" "<<dis[i]<<endl;
            dino = LCMFinder(dino, dis[i]);
        }

        for(int i = 0; i < dis.size(); i++){
            nus[i] = nus[i]*(dino/dis[i]);
        }

        int numo = accumulate(nus.begin(), nus.end(), 0);
        // cout<<numo<<"/"<<dino<<endl;

        if(numo == 0){
            return "0/1";
        }
        int gcd = GCDFinder(numo, dino);
        numo = numo/gcd;
        dino = dino/gcd;

        return to_string(numo)+"/"+to_string(dino);
    }
};