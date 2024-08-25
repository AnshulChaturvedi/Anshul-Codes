class Solution {
public:
    int dp[2001];

    bool isPalindrome(string &s,int st,int e){
        while(st<e){
            if(s[st++] != s[e--]) return false;
        }
        return true;
    }
    int solve(int i,int n,string &s){
        if(i == n) return -1;
        if(dp[i] != -1) return dp[i]; 
        int ans = INT_MAX;
        for(int k=i;k<n;k++){
            int cuts = INT_MAX;
            if(isPalindrome(s,i,k)){
                cuts = 1 + solve(k+1,n,s);
            }
            ans = min(ans,cuts);
        }
        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,s);
    }
};