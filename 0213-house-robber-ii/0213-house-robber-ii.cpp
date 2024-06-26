class Solution {
private:
    int solve(int s, int e, vector<int> &nums,vector<int> &dp){
        if(s>e){
            return 0;
        }
        if(dp[s] != -1){
            return dp[s];
        }
        int rob = solve(s+2,e,nums,dp) + nums[s];
        int notRob = solve(s+1,e,nums,dp);
        return dp[s] = max(rob,notRob);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        if(n == 3) return max(nums[0],max(nums[1],nums[2]));

        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);

        return max(solve(0,n-2,nums,dp1),solve(1,n-1,nums,dp2));
    }
};