class Solution {
// private:
//     double findPow(long double a, int b){
//         if(b == 0) return 1;
//         long double temp = findPow(a,b/2);
//         long double result = temp * temp;
//         if(b%2 == 1) result *= a;
//         return result;
//     }

public:
    double myPow(double a, int n) {
        // if(n<0){
        //     int nn = (long long)n*-1;
        //     return 1/findPow(x,nn);
        // }
        // return findPow(x,n);

        long double result = 1;
        long long b = n;
        if(n<0){
            b = (long long)b * -1;
        }
        while(b>0){
            if(b%2 == 1) result *= a;
            a *= a;
            b /= 2;
        }
        return (n<0) ? (1/result) : result;
    }
};