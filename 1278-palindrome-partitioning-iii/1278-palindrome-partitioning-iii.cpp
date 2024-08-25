class Solution {
public:
    int dp[101][101];
    
    int makePalindrome(string &s,int st,int e){
        int cnt = 0;
        while(st<e){
            if(s[st++] != s[e--]) cnt++;
        }
        return cnt;
    }

    int solve(int i,int n,string &s,int k){
        if(i == n) return (k == 0) ? 0 : 1e6;
        if(k == 0) return 1e6;

        if(dp[i][k] != -1) return dp[i][k];

        int ans = 1e6;

        for(int j=i;j<n;j++){
            int charChange = makePalindrome(s,i,j) + solve(j+1,n,s,k-1);
            ans = min(ans,charChange);
        }
        return dp[i][k] = ans;
    }

    int palindromePartition(string s, int k) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,s,k);
    }
};