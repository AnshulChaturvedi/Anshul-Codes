class Solution {
private:
    bool solve(int n,vector<int> &nums,int target,vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }
        if(n < 0){
            return false;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        if(nums[n] <= target){
            return dp[n][target] = solve(n-1,nums,target-nums[n],dp) || solve(n-1,nums,target,dp);
        }
        return dp[n][target] = solve(n-1,nums,target,dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;

        int target = sum / 2;

        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return solve(n-1,nums,target,dp);
    }
};