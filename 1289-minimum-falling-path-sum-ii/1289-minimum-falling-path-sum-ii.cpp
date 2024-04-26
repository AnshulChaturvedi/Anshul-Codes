class Solution {
public:
    const int inf = 1e9;
    int minFallingPathSum(vector<vector<int>>& grid) {
        int sum = 0;
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int> (n,inf));
        //dp[i,j] = mini falling path sum from [0,0] to [i,j]
        int mini = 1e9;
        for(int j=0;j<n;j++){
            dp[0][j] = grid[0][j];
            mini = min(mini,dp[0][j]);
        }
        sum += mini;
        if(n == 1) return sum;
        else sum = 0;

        for(int i=1;i<n;i++){
            int miniRowSum = inf;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(k != j)
                        dp[i][j] = min(dp[i-1][k]+grid[i][j],dp[i][j]);
                }
                miniRowSum = min(miniRowSum,dp[i][j]);
            }
            sum = miniRowSum;
        }
        return sum;
    }
};