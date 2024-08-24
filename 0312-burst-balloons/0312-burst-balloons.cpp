class Solution {
public:
    int dp[303][303];
    int solve(int l,int r,vector<int> &nums){
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int res = -1;
        for(int i=l;i<=r;i++){
            int coins = (nums[l-1]*nums[i]*nums[r+1]) + solve(l,i-1,nums) + solve(i+1,r,nums);
            res = max(res,coins);
        }
        return dp[l][r] = res;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        memset(dp,-1,sizeof(dp));
        return solve(1,n,nums);
    }
};