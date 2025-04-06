class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> dp;
    vector<vector<bool>> choice;

    int solve(int i, int prev){
        if(i == n) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int skip = solve(i+1, prev);

        if(prev < 0 || nums[i] % nums[prev] == 0){
            int take = 1 + solve(i+1, i);
            if(take > skip){
                skip = take;
                choice[i][prev+1] = 1;
            }
        }
        return dp[i][prev+1] = skip;
    }

    vector<int> buildAns(){
        vector<int> ans;
        int i=0, prev=-1;
        while(i<n){
            if(choice[i][prev+1]){
                ans.push_back(nums[i]);
                prev = i;
            }
            i++;
        }
        return ans;
    }

    vector<int> largestDivisibleSubset(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        sort(nums.begin(), nums.end());

        dp.assign(n, vector<int> (n+1, -1));
        choice.assign(n, vector<bool> (n+1, false));

        solve(0, -1);
        return buildAns();
    }
};