class Solution {
private:
    int robRange(vector<int> &nums,int s,int e){
        int n = e - s + 1;//no. of houses range who can be robbed
        if(n == 1){
            return nums[s];
        }
        vector<int> dp(n,-1);
        //dp[i] represents the maxi money robbed till ith index house
        dp[0] = nums[s];
        dp[1] = max(nums[s],nums[s+1]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i+s]);
        }
        return dp[n-1];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(robRange(nums,0,n-2),robRange(nums,1,n-1));
    }
};