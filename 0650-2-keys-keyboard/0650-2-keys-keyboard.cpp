class Solution {
public:
    // int solve(int n){
    //     if(n == 1) return 0;
    //     int copy = 0;
        
    // }
    bool prime(int n){
        for(int i=2; i*i <= n; i++){
            if(n%i == 0) return false;
        }
        return true;
    }

    int minSteps(int n) {
        if(n == 1) return 0;
        // if(prime(n)) return n;
        // return solve(n);
        // vector<vector<int>> dp(n+1, vector<int> (2));
        // dp[1][0] = 0; // [0] copy
        // dp[1][1] = 0; // [1] paste
        // for(int i=2; i<=n; i++){
        //     dp[i][k] = min(dp[i-1][0], dp[i-1][1]) + 1;
        // }
        // return min(dp[n][0], dp[n][1]);
        int cnt = 0;
        while(n%2 == 0){
            n /= 2;
            cnt += 2;
        }
        for(int i=3; i*i<=n; i+=2){
            while(n%i == 0){
                cnt += i;
                n /= i;
            }
        }
        if(n > 1) cnt += n;
        return cnt;
    }
};