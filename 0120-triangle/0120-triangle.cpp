class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = 0;
        for(int i=0;i<n;i++){
            int val = triangle[i].size();
            m = max(m,val);
        }
        vector<vector<int>> dp(n,vector<int> (m,0));
        //dp[i][j] represents the mini sum from ith row if curr chosen col is j
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(i == n-1){
                    dp[i][j] = triangle[i][j];
                }
                else{
                    dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j];
                }
            }
        }
        return dp[0][0];
    }
};