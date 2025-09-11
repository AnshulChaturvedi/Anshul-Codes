class Solution {
public:
    int dp[601][101][101];
    int solve(int i, int m, int n, vector<string>& strs){
        if(i >= strs.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int oneCnt = count(strs[i].begin(),strs[i].end(),'1');
        int zeroCnt = count(strs[i].begin(),strs[i].end(),'0');
        int take = 0;
        if(oneCnt <= n && zeroCnt <= m){
            take = solve(i+1,m-zeroCnt,n-oneCnt,strs) + 1;
        }
        int skip = solve(i+1,m,n,strs);
        return dp[i][m][n] = max(take,skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,m,n,strs);
    }
};