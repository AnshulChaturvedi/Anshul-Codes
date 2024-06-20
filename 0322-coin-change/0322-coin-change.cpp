class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,1e9);
        //mini no of coins to make amount till i index
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(coins[j] <= i){
                    dp[i] = min(dp[i],dp[i-coins[j]] + 1);
                }
            }
        }
        return (dp[amount] == 1e9) ? -1 : dp[amount];
    }
};