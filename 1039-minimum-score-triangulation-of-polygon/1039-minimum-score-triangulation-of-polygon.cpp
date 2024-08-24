class Solution {
public:
    int dp[51][51];
    int solve(vector<int> &v,int st,int e){
        if(st+1 == e) return 0;
        if(dp[st][e] != -1) return dp[st][e];
        int res = INT_MAX;
        for(int k=st+1;k<=e-1;k++){
            int score = (v[st]*v[k]*v[e]) + solve(v,st,k) + solve(v,k,e);
            res = min(res,score);
        }
        return dp[st][e] = res;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(dp,-1,sizeof(dp));
        return solve(values,0,n-1);
    }
};