class Solution {
public:
    const int M = 1e9 + 7;
    int solve(int i, int n, int x, int sum, vector<vector<int>> &dp, vector<int> &powers){
        if(sum == n){
            return 1;
        }
        if(i >= powers.size() || sum > n) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        int take = solve(i+1,n,x,sum + powers[i],dp,powers) % M;
        int skip = solve(i+1,n,x,sum,dp,powers) % M;
        return dp[i][sum] = (take + skip) % M;
    }

    int numberOfWays(int n, int x) {
        int sum = 0;
        vector<int> powers;
        for(int i=1; ; i++){
            long long val = pow(i,x);
            if(val > n) break;
            powers.push_back((int)val);
        }
        vector<vector<int>> dp(powers.size(), vector<int> (n+1,-1));
        return solve(0,n,x,sum,dp,powers);
    }
};