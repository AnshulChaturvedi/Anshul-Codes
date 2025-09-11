class Solution {
public:
    int dp[21][2001];
    int offset = 1000;
    int solve(int i, int sum, vector<int>& nums, int target){
        if(i == nums.size() && sum == target) return 1;
        if(i >= nums.size()) return 0;
        if(dp[i][sum + offset] != -1) return dp[i][sum + offset];
        int pos = solve(i+1, sum + nums[i], nums, target);
        int neg = solve(i+1, sum - nums[i], nums, target);
        return dp[i][sum + offset] = pos + neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums,target);
    }
};