class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &s,string &t){
        if(j >= t.size())
            return 1;
        if(i >= s.size())
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j])
            return dp[i][j] = solve(i+1,j+1,s,t) + solve(i+1,j,s,t);
        return dp[i][j] = solve(i+1,j,s,t);
    }

    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    }
};