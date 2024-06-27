class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()){
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int> (m));
        //dp[i][j] represents the maxi length square to [i,j] from [0,0]
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1;
                    if(i>0 && j>0){
                        dp[i][j] += min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
                    }
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};