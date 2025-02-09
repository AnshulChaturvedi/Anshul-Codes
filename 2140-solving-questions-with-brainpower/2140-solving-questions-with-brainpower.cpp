class Solution {
public:
    // long long solve( int i, vector<vector<int>>& questions){
    //     if(i >= questions.size()) return 0;
    //     long long take = questions[i][0] + solve(i + questions[i][1] + 1, questions);
    //     long long skip = solve(i+1, questions);
    //     return max(take, skip);
    // }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        // dp[i] represents the maxi points till ith index
        vector<long long> dp(n+1,0);
        for(int i=n-1; i>=0; i--){
            long long nextIndex = i + questions[i][1] + 1;
            long long take = questions[i][0];
            if(nextIndex < dp.size()){
                take += dp[nextIndex];
            }
            long long skip = dp[i+1];
            dp[i] = max(take , skip);
        }
        return dp[0];
        // return solve(0, questions);
    }
};