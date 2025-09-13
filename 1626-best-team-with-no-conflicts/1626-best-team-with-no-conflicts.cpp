class Solution {
public:
    int n;
    // int dp[1001][1000000001];
    int solve(int i, int currScore, vector<pair<int,int>>& arr, vector<vector<int>>& dp){
        // if(scores[i] > maxScore && ages[i] < minAge){
        //     skip = solve(i+1, scores, ages);
        // }
        // if(i == n) return 0;
        // if(dp[ages[i]] == -1){
        //     dp[ages[i]] = scores[i];
        // }
        // if(dp[ages[i]] != -1){
        //     if(dp[ages[i]] < scores[i]) dp[ages[i]] = scores[i];
        // }
        if(i >= n) return 0;
        if(dp[i][currScore] != -1) return dp[i][currScore];
        int scr = arr[i].second, age = arr[i].first;
        int take = 0; 
        if(scr >= currScore){
            take = solve(i+1, scr, arr, dp) + scr;
        }
        int skip = solve(i+1, currScore, arr, dp);
        return dp[i][currScore] = max(take, skip);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n = scores.size();
        // memset(dp,-1,sizeof(dp));
        // int totalScr = accumulate(scores.begin(), scores.end(), 0);
        // vector<vector<int>> dp(n+1, vector<int> (totalScr+1,-1));
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = {ages[i], scores[i]};
        }
        sort(arr.begin(), arr.end());
        // return solve(0, 0, arr, dp);

        vector<int> dp(n,0);
        dp[0] = arr[0].second;
        for(int i=1; i<n; i++){
            int ans = arr[i].second;
            for(int j=0; j<i; j++){
                if(arr[j].second <= arr[i].second){
                    ans = max(arr[i].second + dp[j], ans);
                }
            }
            dp[i]=ans;
        }
        int res = 0;
        for(int i=0; i<n; i++){
            res = max(res, dp[i]);
        }
        return res;
    }
};