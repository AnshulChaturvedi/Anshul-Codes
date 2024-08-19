class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int prev,int n,vector<vector<int>> &pairs){
        if(i>=n) return 0;
        if(prev != -1 && dp[i][prev] != -1){
            return dp[i][prev];
        }
        int take = 0;
        if(prev == -1 || pairs[i][0] > pairs[prev][1]){
            take = 1 + solve(i+1,i,n,pairs);
        }
        int notTake = solve(i+1,prev,n,pairs);
        if(prev != -1){
            dp[i][prev] = max(take,notTake);
        }
        return max(take,notTake);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,n,pairs);
    }
};