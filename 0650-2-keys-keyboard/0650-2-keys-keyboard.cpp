class Solution {
private:
    vector<int> factors(int n){
        vector<int> ans(2,1);
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                ans[1] = i;
                ans[0] = n/i;
            }
        }
        return ans;
    }


    bool isPrime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        if(isPrime(n)) return n;
        
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4;i<=n;i++){
            if(isPrime(i)){
                dp[i] = i;
            }
            else{
                vector<int> fac = factors(i);
                dp[i] = dp[fac[0]] + dp[fac[1]];
            }
        }
        return dp[n];
    }
};