class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return "";
        if(n == 1) return s;

        int st = 0;
        int maxLen = 1;

        vector<vector<bool>> dp(n,vector<bool> (n,false));
        //dp[i][j] represents that whether the str from i to j isPalindrome or not
        //B
        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                st = i;
                maxLen = 2;
            }
        }

        //T
        for(int len=3;len<=n;len++){
            for(int i=0;i<n+1-len;i++){
                int j = i+len-1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(len > maxLen){
                        maxLen = len;
                        st = i;
                    }
                }
            }
        }
        return s.substr(st,maxLen);
    }
};