class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);//len of LIS
        vector<int> count(n, 1); //count till ith index
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[j] < nums[i]){
                    if(dp[j] + 1 == dp[i]){
                        count[i] += count[j];
                    }
                    else if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
        }
        int maxi = *max_element(dp.begin(), dp.end());
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi){
                cnt += count[i];
            }
        }
        return cnt;
    }
};