class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        if((totalSum+target)&1 || totalSum < abs(target)) return 0;

        int reqVal = (totalSum + target) / 2;
        vector<vector<int>> dp(n+1,vector<int> (reqVal+1,0));
        //dp[i][j] represents the no of subsets with sum equal to j with arr length of n
        dp[0][0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=reqVal;j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i-1] <= j){
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][reqVal];
    }
};