class Solution {
public:
    int memo[2501][2502];
    int solve(int i,vector<int> &nums,int last){
        if(i>=nums.size()){
            return 0;
        }
        if(memo[i][last+1] != -1){
            return memo[i][last+1];
        }
        int take = 0;
        if(last == -1 || nums[i] > nums[last]){
            take = solve(i+1,nums,i) + 1;
        }
        int nottake = solve(i+1,nums,last);
        return memo[i][last+1] = max(take,nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        memset(memo,-1,sizeof(memo));
        return solve(0,nums,-1);
    }
};