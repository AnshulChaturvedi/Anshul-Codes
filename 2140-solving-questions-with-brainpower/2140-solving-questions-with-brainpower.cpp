class Solution {
public:
    // long long solve(int i, int n, vector<vector<int>>& questions){
    //     if(i >= n) return 0;
    //     long long take = solve(i + questions[i][1] + 1, n, questions) + questions[i][0];
    //     long long notTake = solve(i+1, n, questions);
    //     return max(take, notTake);
    // }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        // return solve(0, n, questions);
        vector<long long> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            long long nxtIdx = i + questions[i][1] + 1;
            long long take = questions[i][0];
            if(nxtIdx < questions.size()){
                take += dp[nxtIdx];
            }
            long long skip = dp[i+1];
            dp[i] = max(take, skip);
        }
        return dp[0];
    }
};