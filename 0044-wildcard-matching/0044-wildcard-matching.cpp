class Solution {
public:
    int dp[2001][2001];
    bool solve(int i,int j,int n,int m, string &s, string &p){
        if(i == n && j == m) return true;
        if(j == m) return false;
        if(i == n){
            while(j<m && p[j] == '*') j++;
            return j == m;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == '*'){
            dp[i][j] = solve(i+1,j,n,m,s,p) || solve(i,j+1,n,m,s,p);
        }
        else if(p[j] == '?' || s[i] == p[j]){
            dp[i][j] = solve(i+1,j+1,n,m,s,p);
        }
        else{
            dp[i][j] = false;
        }
        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,m,s,p);
    }
};