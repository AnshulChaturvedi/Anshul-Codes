using ll = long long;

class Solution {
public:
    double myPow(double x, int n) {

        long double result = 1;
        ll b = n;

        if(n<0) b = (ll)-1 * n;

        while(b>0){
            if(b%2 == 1) result *= x;
            x *= x;
            b /= 2;
        }
        
        if(n<0){
            return 1/result;
        }
        return result;
    }
};