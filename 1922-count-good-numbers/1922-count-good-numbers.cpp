class Solution {
public:
    const int MOD = 1000000007;

    long long modExp(long long base, long long exp){
        long long res = 1;
        while(exp > 0){
            if(exp & 1){
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenIdx = (n + 1) / 2; //ceil
        long long oddIdx = n / 2; //floor
        return (modExp(5, evenIdx) * modExp(4, oddIdx))% MOD;
    }
};