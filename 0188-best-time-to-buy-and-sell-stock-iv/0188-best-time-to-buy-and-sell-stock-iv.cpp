class Solution {
public:
    int maxProfit(int m, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (m+1,0)));
        //dp[i][k][l] represents the maximum profit obtained from i to nth day and either 
        // we buy stock at ith day(k == 1) or not(k == 0) with l transactions remaining
        for(int i=n-1;i>=0;i--){
            for(int k=0;k<=1;k++){
                for(int l=1;l<=m;l++){
                    if(k == 1){// buy
                        dp[i][k][l] = max(dp[i+1][0][l] - prices[i], dp[i+1][1][l]); 
                    }
                    else{// sell
                        dp[i][k][l] = max(dp[i+1][1][l-1] + prices[i], dp[i+1][0][l]); 
                    }
                }
            }
        }
        return dp[0][1][m];
    }
};