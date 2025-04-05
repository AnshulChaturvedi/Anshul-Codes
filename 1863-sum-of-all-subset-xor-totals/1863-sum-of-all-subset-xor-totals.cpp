class Solution {
public:
    void solve(int i, int n, vector<int>& nums, int &ans, int curr_xor){
        if(i >= n){
            ans += curr_xor;
            return;
        }
        solve(i+1, n, nums, ans, curr_xor^nums[i]);
        solve(i+1, n, nums, ans, curr_xor);
    }

    int subsetXORSum(vector<int>& nums) {
        // generate all subsets and sum the value of each xor subset of them
        int n = nums.size();
        int ans = 0;
        solve(0, n, nums, ans, 0);
        return ans;
    }
};