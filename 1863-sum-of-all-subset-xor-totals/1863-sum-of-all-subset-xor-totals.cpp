class Solution {
public:
    int solve(vector<int> &nums, int i, int currXOR){
        if(i == nums.size()) return currXOR;
        int take = solve(nums, i+1, currXOR^nums[i]);
        int skip = solve(nums, i+1, currXOR);
        return take + skip;
    }
    int subsetXORSum(vector<int>& nums) {
        // return solve(nums, 0, 0);
        int res = 0;
        for(auto &num : nums) res |= num;
        return (res << (nums.size()-1));
    }
};