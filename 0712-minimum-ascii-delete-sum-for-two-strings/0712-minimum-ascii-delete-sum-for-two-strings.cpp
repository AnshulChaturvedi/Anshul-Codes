class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //minDeleteSum = asciiSum(s1) + asciiSum(s2) - 2 * asciiSum(LCS)
        int asciiSum1 = 0;
        for(auto &c : s1){
            asciiSum1 += c;
        }
        int asciiSum2 = 0;
        for(auto &c : s2){
            asciiSum2 += c;
        }

        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        //dp[i][j] represents the maximum sum lcs till i length s1 and j length s2
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1] + s1[i-1]);
                }
                else{
                    dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        int asciiSumLCS = dp[n][m];

        return asciiSum1 + asciiSum2 - 2 * asciiSumLCS;
    }
};