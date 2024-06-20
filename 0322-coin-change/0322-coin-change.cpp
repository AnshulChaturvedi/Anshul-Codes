class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n+1,vector<int> (amount+1,1000000));
        //dp[i][j] represents the mini no. of coins req to make amount j with i items

        for(int i=1;i<=n;i++){
            dp[i][0] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1] <= j ){
                    dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (dp[n][amount] == 1000000) ? -1 : dp[n][amount];
    }
};