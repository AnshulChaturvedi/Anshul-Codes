class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int> (m,0));
        //dp[i][j] represents the mini falling pathSum from ith row to nth row s.t curr choosen col is j
        for(int j=0;j<m;j++){
            dp[n-1][j] = matrix[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(j == m-1){
                    dp[i][j] = min(dp[i+1][j],dp[i+1][j-1]) + matrix[i][j];
                }
                else if(j == 0){
                    dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + matrix[i][j];
                }
                else{
                    dp[i][j] = min(dp[i+1][j],min(dp[i+1][j+1],dp[i+1][j-1])) + matrix[i][j];
                }
            }
        }
        int ans = INT_MAX;
        for(int j=0;j<m;j++){
            ans = min(ans,dp[0][j]);
        }
        return ans;
    }
};