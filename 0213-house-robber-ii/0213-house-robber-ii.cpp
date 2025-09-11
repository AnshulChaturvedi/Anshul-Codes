class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums, int s, int e){
        if(s > e) return 0;
        if(dp[s] != -1) return dp[s];
        int take = solve(nums, s+2, e) + nums[s];
        int notTake = solve(nums, s+1, e);
        return dp[s] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max({nums[0], nums[1], nums[2]});
        memset(dp,-1,sizeof(dp));
        int first = solve(nums,0,n-2);
        memset(dp,-1,sizeof(dp));
        int second = solve(nums,1,n-1);
        return max(first, second);
    }
};