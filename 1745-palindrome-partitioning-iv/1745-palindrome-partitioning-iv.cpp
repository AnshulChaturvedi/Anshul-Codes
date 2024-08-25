class Solution {
public:

    int dp[2001][4];
    bool isPalindrome(string &s,int st,int e){
        while(st<e){
            if(s[st++] != s[e--]) return false;
        }
        return true;
    }

    bool solve(int i,int n,string &s,int k){
        if(i == n) return k==0;
        if(k == 0) return false;

        if(dp[i][k] != -1) return dp[i][k];

        int ans = 0;

        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                if(solve(j+1,n,s,k-1)){
                    ans = 1;
                    break;
                }
            }
        }
        return dp[i][k] = ans;
    }

    bool checkPartitioning(string s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,s,3);
    }
};