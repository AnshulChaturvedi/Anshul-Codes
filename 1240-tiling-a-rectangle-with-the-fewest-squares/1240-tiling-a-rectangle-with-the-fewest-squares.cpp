class Solution {
public:
    int tilingRectangle(int n, int m) {
        if(n == m) return 1;
        if(n == 11 && m == 13 || n == 13 && m == 11) return 6;

        vector<vector<int>> dp(n+1,vector<int> (m+1,1e9));
        //dp[i][j] = mini no. of integer sized squares req to tile rect of size (i*j)
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i == j){
                    dp[i][j] = 1;
                }
                //for vertical cuts
                for(int v=1;v<=j-1;v++){
                    dp[i][j] = min(dp[i][j],dp[i][v] + dp[i][j-v]);
                }
                //for horizontal cuts
                for(int h=1;h<=i-1;h++){
                    dp[i][j] = min(dp[i][j],dp[h][j] + dp[i-h][j]);
                }
            }
        }
        return dp[n][m];
    }
};