class Solution {
public:
    int dp[10001];
    int solve(int i,vector<int> &nums,int n){
        if(i >= n-1) return 1;
        if(nums[i] == 0) return 0;
        if(dp[i] != -1) return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(solve(i+j,nums,n)) return dp[i+1] = 1;
        }
        return dp[i] = 0;
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        int val = solve(0,nums,n);
        return (val == 1) ? true : false;
    }
};