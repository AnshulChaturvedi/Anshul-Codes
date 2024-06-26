class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        //points array jo sabka maximum element ko bhi contain karta ho
        int m = *max_element(nums.begin(),nums.end()) + 1;
        vector<int> points(m,0);
        for(auto &num : nums){
            points[num] += num;
        }

        vector<int> dp(m,0);
        //dp[i] represents the maximum Value we can achieve by considering elements upto i
        dp[0] = points[0];
        dp[1] = max(points[0],points[1]);
        for(int i=2;i<m;i++){
            dp[i] = max( dp[i-2] + points[i] , dp[i-1]);
        }
        return dp[m-1];
    }
};