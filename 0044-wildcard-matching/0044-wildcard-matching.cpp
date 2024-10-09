class Solution {
public:
    int dp[2001][2001];
    bool solve(int i,int j,int n,int m, string &s, string &p){
        if(i==n && j<m){
            while(j<m && p[j] == '*') j++;
            if(j==m) return true;
        }
        if((i<n && j == m) || (i == n && j<m)) return false;
        if(i == n && j == m) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == '*'){
            return dp[i][j] = solve(i+1,j+1,n,m,s,p) || solve(i+1,j,n,m,s,p) || solve(i,j+1,n,m,s,p);
        }
        if(p[j] == '?'){
            return dp[i][j] = solve(i+1,j+1,n,m,s,p);
        }
        if(s[i] == p[j]){
            return dp[i][j] = solve(i+1,j+1,n,m,s,p);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,m,s,p);
    }
};