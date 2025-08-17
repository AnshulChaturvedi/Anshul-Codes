class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        // while(n % 4 == 0) n /= 4;
        // return n == 1;
        double x = (double) log10(n) / log10(4);
        return fabs(x - round(x)) ==0;
    }
};