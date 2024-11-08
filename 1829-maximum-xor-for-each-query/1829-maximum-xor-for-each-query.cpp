class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maxBit) {
        int n = nums.size();
        vector<int> ans(n);
        int cummXOR = 0;
        for(auto num : nums) cummXOR ^= num;
        int maxXOR = (1<<maxBit)-1;
        for(int i=0;i<n;i++){
            ans[i] = cummXOR ^ maxXOR;
            cummXOR ^= nums[n-1-i];
        }
        return ans;
    }
};