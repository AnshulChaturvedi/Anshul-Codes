using ll = long long;

class Solution {
private:
    ll power(ll a, ll b){
        ll result = 1;
        while(b>0){
            if(b&1){
                result = ((result%M)*(a%M))%M;
            }
            a = ((a%M)*(a%M))%M;
            b /= 2;
        }
        return result;
    }
public:
    const int M = 1e9 + 7;
    int countGoodNumbers(long long n) {
        // for even place 5 choices (0,2,4,6,8)
        // for odd places 4 chices (2,3,5,7)
        ll oddIndexes = n/2;
        ll evenIndexes = oddIndexes;
        if(n&1) evenIndexes++;

        ll ans1 = power(5,evenIndexes);
        ll ans2 = power(4,oddIndexes);

        return ((ans1%M)*(ans2%M))%M;

    }
};