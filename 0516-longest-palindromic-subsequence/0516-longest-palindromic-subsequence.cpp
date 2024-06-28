class Solution {
private:
    int memo[1001][1001];
    int solve(int i,int j,string &s){
        if(i==j){
            return 1;
        }
        if(i>j){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(s[i] == s[j]){
            return memo[i][j] = solve(i+1,j-1,s) + 2;
        }
        int l = solve(i,j-1,s);
        int r = solve(i+1,j,s);
        return memo[i][j] = max(l,r);
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n == 1) return 1;

        memset(memo,-1,sizeof(memo));
        return solve(0,n-1,s);
    }
};